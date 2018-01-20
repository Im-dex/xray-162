// Rain.h: interface for the CRain class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ThunderboltH
#define ThunderboltH
#pragma once

// refs
class ENGINE_API IRender_DetailModel;
class ENGINE_API CLAItem;

#include "xrRender/FactoryPtr.h"
#include "xrRender/LensFlareRender.h"
#include "xrRender/ThunderboltDescRender.h"
#include "xrRender/ThunderboltRender.h"

#ifdef INGAME_EDITOR
#define INGAME_EDITOR_VIRTUAL virtual
#else // #ifdef INGAME_EDITOR
#define INGAME_EDITOR_VIRTUAL
#endif // #ifdef INGAME_EDITOR

class CEnvironment;

struct SThunderboltDesc {
    // geom
    // IRender_DetailModel*		l_model;
    FactoryPtr<IThunderboltDescRender> m_pRender;
    // sound
    ref_sound snd;
    // gradient
    struct SFlare {
        float fOpacity;
        Fvector2 fRadius;
        std::string texture;
        shared_str shader;
        // ref_shader				hShader;
        FactoryPtr<IFlareRender> m_pFlare;
        SFlare() {
            fOpacity = 0;
            fRadius.set(0.f, 0.f);
        }
    };
    SFlare* m_GradientTop;
    SFlare* m_GradientCenter;
    shared_str name;
    CLAItem* color_anim;

public:
    SThunderboltDesc();
    INGAME_EDITOR_VIRTUAL ~SThunderboltDesc();
    void load(CInifile& pIni, shared_str const& sect);
    INGAME_EDITOR_VIRTUAL void create_top_gradient(CInifile& pIni, shared_str const& sect);
    INGAME_EDITOR_VIRTUAL void create_center_gradient(CInifile& pIni, shared_str const& sect);
};

#undef INGAME_EDITOR_VIRTUAL

struct SThunderboltCollection {
    using DescVec = std::vector<SThunderboltDesc*>;
    DescVec palette;
    std::string section;

public:
    SThunderboltCollection();
    ~SThunderboltCollection();
    void load(CInifile* pIni, CInifile* thunderbolts, LPCSTR sect);
    SThunderboltDesc* GetRandomDesc() {
        VERIFY(!palette.empty());
        return palette[Random.randI(palette.size())];
    }
};

#define THUNDERBOLT_CACHE_SIZE 8
//
class ENGINE_API CEffect_Thunderbolt {
    friend class dxThunderboltRender;

protected:
    using CollectionVec = std::vector<SThunderboltCollection*>;
    CollectionVec collection;
    SThunderboltDesc* current;

private:
    Fmatrix current_xform;
    Fvector3 current_direction;

    FactoryPtr<IThunderboltRender> m_pRender;
    // ref_geom			  		hGeom_model;
    // states
    enum EState { stIdle, stWorking };
    EState state;

    // ref_geom			  		hGeom_gradient;

    Fvector lightning_center;
    float lightning_size;
    float lightning_phase;

    float life_time;
    float current_time;
    float next_lightning_time;
    BOOL bEnabled;

    // params
    //	Fvector2					p_var_alt;
    //	float						p_var_long;
    //	float						p_min_dist;
    //	float						p_tilt;
    //	float						p_second_prop;
    //	float						p_sky_color;
    //	float						p_sun_color;
    //	float						p_fog_color;
private:
    static BOOL RayPick(const Fvector& s, const Fvector& d, float& range);
    void Bolt(const std::string& id, const float period, const float life_time);

public:
    CEffect_Thunderbolt();
    ~CEffect_Thunderbolt();

    void OnFrame(const std::string& id, const float period, const float duration);
    void Render();

    std::string AppendDef(CEnvironment& environment, CInifile* pIni, CInifile* thunderbolts,
                         LPCSTR sect);
};

#endif // ThunderboltH