//----------------------------------------------------
#ifndef MotionH
#define MotionH

#ifdef _LW_EXPORT
#include <lwrender.h>
#include <lwhost.h>
#endif

#include "bone.h"

// refs
class CEnvelope;
class IWriter;
class IReader;
class motion_marks;

enum EChannelType {
    ctUnsupported = -1,
    ctPositionX = 0,
    ctPositionY,
    ctPositionZ,
    ctRotationH,
    ctRotationP,
    ctRotationB,
    ctMaxChannel
};

struct st_BoneMotion {
    enum {
        flWorldOrient = 1 << 0,
    };
    shared_str name;
    CEnvelope* envs[ctMaxChannel];
    Flags8 m_Flags;
    st_BoneMotion() {
        name = 0;
        m_Flags.zero();
        std::memset(envs, 0, sizeof(CEnvelope*) * ctMaxChannel);
    }
    void SetName(LPCSTR nm) { name = nm; }
};
// vector �� ������
using BoneMotionVec = xr_vector<st_BoneMotion>;

//--------------------------------------------------------------------------
class ENGINE_API CCustomMotion {
protected:
    enum EMotionType { mtObject = 0, mtSkeleton, ForceDWORD = u32(-1) };
    EMotionType mtype;
    int iFrameStart, iFrameEnd;
    float fFPS;

public:
    shared_str name;

public:
    CCustomMotion();
    CCustomMotion(CCustomMotion* src);
    virtual ~CCustomMotion();

    void SetName(const char* n) {
        string256 tmp;
        tmp[0] = 0;
        if (n) {
            xr_strcpy(tmp, n);
            strlwr(tmp);
        }
        name = tmp;
    }
    LPCSTR Name() { return name.c_str(); }
    int FrameStart() { return iFrameStart; }
    int FrameEnd() { return iFrameEnd; }
    float FPS() { return fFPS; }
    int Length() { return iFrameEnd - iFrameStart + 1; }

    void SetParam(int s, int e, float fps) {
        iFrameStart = s;
        iFrameEnd = e;
        fFPS = fps;
    }

    virtual void Save(IWriter& F);
    virtual bool Load(IReader& F);

    virtual void SaveMotion(const char* buf) = 0;
    virtual bool LoadMotion(const char* buf) = 0;

#ifdef _LW_EXPORT
    CEnvelope* CreateEnvelope(LWChannelID chan, LWChannelID* chan_parent = 0);
#endif
};

//--------------------------------------------------------------------------
class ENGINE_API COMotion : public CCustomMotion {
    CEnvelope* envs[ctMaxChannel];

public:
    COMotion();
    COMotion(COMotion* src);
    virtual ~COMotion();

    void Clear();

    void _Evaluate(float t, Fvector& T, Fvector& R);
    virtual void Save(IWriter& F);
    virtual bool Load(IReader& F);

    virtual void SaveMotion(const char* buf);
    virtual bool LoadMotion(const char* buf);

#ifdef _LW_EXPORT
    void ParseObjectMotion(LWItemID object);
#endif
#ifdef _EDITOR
    void FindNearestKey(float t, float& min_k, float& max_k, float eps = EPS_L);
    void CreateKey(float t, const Fvector& P, const Fvector& R);
    void DeleteKey(float t);
    void NormalizeKeys();
    int KeyCount();
    CEnvelope* Envelope(EChannelType et = ctPositionX) { return envs[et]; }
    BOOL ScaleKeys(float from_time, float to_time, float scale_factor);
    BOOL NormalizeKeys(float from_time, float to_time, float speed);
    float GetLength(float* mn = 0, float* mx = 0);
#endif
};

//--------------------------------------------------------------------------

enum ESMFlags {
    esmFX = 1 << 0,
    esmStopAtEnd = 1 << 1,
    esmNoMix = 1 << 2,
    esmSyncPart = 1 << 3,
    esmUseFootSteps = 1 << 4,
    esmRootMover = 1 << 5,
    esmIdle = 1 << 6,
    esmUseWeaponBone = 1 << 7,
};

#if defined(_EDITOR) || defined(_MAX_EXPORT) || defined(_MAYA_EXPORT)
#include "SkeletonMotions.h"

class ENGINE_API CSMotion : public CCustomMotion {
    BoneMotionVec bone_mots;

public:
    u16 m_BoneOrPart;
    float fSpeed;
    float fAccrue;
    float fFalloff;
    float fPower;
    Flags8 m_Flags;

    xr_vector<motion_marks> marks;

    void Clear();

public:
    CSMotion();
    CSMotion(CSMotion* src);
    virtual ~CSMotion();

    void _Evaluate(int bone_idx, float t, Fvector& T, Fvector& R);

    void CopyMotion(CSMotion* src);

    st_BoneMotion* FindBoneMotion(shared_str name);
    BoneMotionVec& BoneMotions() { return bone_mots; }
    Flags8 GetMotionFlags(int bone_idx) { return bone_mots[bone_idx].m_Flags; }
    void add_empty_motion(shared_str const& bone_id);

    virtual void Save(IWriter& F);
    virtual bool Load(IReader& F);

    virtual void SaveMotion(const char* buf);
    virtual bool LoadMotion(const char* buf);

    void SortBonesBySkeleton(BoneVec& bones);
    void WorldRotate(int boneId, float h, float p, float b);

    void Optimize();
#ifdef _LW_EXPORT
    void ParseBoneMotion(LWItemID bone);
#endif
};
#endif

struct ECORE_API SAnimParams {
    float t_current;
    float tmp;
    float min_t;
    float max_t;
    BOOL bPlay;
    BOOL bWrapped;

public:
    SAnimParams() {
        bWrapped = false;
        bPlay = false;
        t_current = 0.f;
        min_t = 0.f;
        max_t = 0.f;
        tmp = 0.f;
    }
    void Set(CCustomMotion* M);
    void Set(float start_frame, float end_frame, float fps);
    float Frame() { return t_current; }
    void Update(float dt, float speed, bool loop);
    void Play() {
        bPlay = true;
        t_current = min_t;
        tmp = min_t;
    }
    void Stop() {
        bPlay = false;
        t_current = min_t;
        tmp = min_t;
    }
    void Pause(bool val) { bPlay = !val; }
};

#endif
