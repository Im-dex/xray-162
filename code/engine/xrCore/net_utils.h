#pragma once

#include "client_id.h"

static constexpr const size_t NET_PacketSizeLimit = 16 * 1024;

struct NET_Buffer {
    BYTE data[NET_PacketSizeLimit];
    u32 count;
};

class XRCORE_API NET_Packet {
public:
    NET_Buffer B;
    u32 r_pos;
    u32 timeReceive;

    NET_Packet() 
        : B(),
          r_pos(0),
          timeReceive(0)
    {}

    NET_Packet(const void* data, const size_t size) : NET_Packet() {
        set(data, size);
    }

    void set(const void* data, const size_t size) {
        memcpy(B.data, data, size);
        B.count = size;
    }

    // writing - main
    void write_start() {
        B.count = 0;
    }

    void w_begin(u16 type) {
        B.count = 0;
        w_u16(type);
    }

    struct W_guard {
        bool* guarded;
        W_guard(bool* b) : guarded(b) { *b = true; }
        ~W_guard() { *guarded = false; }
    };

    void w(const void* p, const size_t count) {
        VERIFY(p && count);
        VERIFY(B.count + count < NET_PacketSizeLimit);
        std::memcpy(&B.data[B.count], p, count);
        B.count += count;
        VERIFY(B.count < NET_PacketSizeLimit);
    }

    void w_seek(const u32 pos, const void* p, const u32 count);
    u32 w_tell() const { return B.count; }

    // writing - utilities
    void w_float(const float a) {
        w(&a, sizeof(float));
    } // float

    void w_vec3(const Fvector& a) {
        w(&a, 3 * sizeof(float));
    } // vec3

    void w_vec4(const Fvector4& a) {
        w(&a, 4 * sizeof(float));
    } // vec4

    void w_u64(const u64 a) {
        w(&a, sizeof(u64));
    } // qword (8b)

    void w_s64(const s64 a) {
        w(&a, sizeof(s64));
    } // qword (8b)

    void w_u32(const u32 a) {
        w(&a, sizeof(u32));
    } // dword (4b)

    void w_s32(const s32 a) {
        w(&a, sizeof(s32));
    } // dword (4b)

    void w_u16(const u16 a) {
        w(&a, sizeof(u16));
    } // word (2b)

    void w_s16(const s16 a) {
        w(&a, sizeof(s16));
    } // word (2b)

    void w_u8(const u8 a) {
        w(&a, sizeof(u8));
    } // byte (1b)

    void w_s8(const s8 a) {
        w(&a, sizeof(s8));
    } // byte (1b)

    void w_float_q16(const float a, const float min, const float max) {
        VERIFY(a >= min && a <= max);
        const float q = (a - min) / (max - min);
        w_u16(u16(iFloor(q * 65535.f + 0.5f)));
    }

    void w_float_q8(const float a, const float min, const float max) {
        VERIFY(a >= min && a <= max);
        const float q = (a - min) / (max - min);
        w_u8(u8(iFloor(q * 255.f + 0.5f)));
    }

    void w_angle16(const float a) { w_float_q16(angle_normalize(a), 0.f, PI_MUL_2); }
    void w_angle8(const float a) { w_float_q8(angle_normalize(a), 0.f, PI_MUL_2); }
    void w_dir(const Fvector& D) { w_u16(pvCompress(D)); }
    void w_sdir(const Fvector& D) {
        Fvector C;
        float mag = D.magnitude();
        if (mag > EPS_S) {
            C.div(D, mag);
        } else {
            C.set(0, 0, 1);
            mag = 0;
        }
        w_dir(C);
        w_float(mag);
    }

    void w_stringZ(const char* S) {
        w(S, xr_strlen(S) + 1);
    }

    void w_stringZ(const std::string_view str) {
        w(str.data(), str.size());
        w_u8(0);
    }

    void w_stringZ(const shared_str& p) {
        if (*p)
            w(*p, p.size() + 1);
        else
            w_u8(0);
    }

    void w_matrix(const Fmatrix& M) {
        w_vec3(M.i);
        w_vec3(M.j);
        w_vec3(M.k);
        w_vec3(M.c);
    }

    void w_clientID(ClientID C) { w_u32(C.value()); }

    void w_chunk_open8(u32& position) {
        position = w_tell();
        w_u8(0);
    }

    void w_chunk_close8(const u32 position) {
        const u32 size = u32(w_tell() - position) - sizeof(u8);
        VERIFY(size < 256);
        const u8 _size = static_cast<u8>(size);
        w_seek(position, &_size, sizeof(_size));
    }

    void w_chunk_open16(u32& position) {
        position = w_tell();
        w_u16(0);
    }

    void w_chunk_close16(const u32 position) {
        const u32 size = u32(w_tell() - position) - sizeof(u16);
        VERIFY(size < 65536);
        const u16 _size = static_cast<u16>(size);
        w_seek(position, &_size, sizeof(_size));
    }

    // reading
    void read_start() {
        r_pos = 0;
    }

    u32 r_begin(u16& type);
    void r_seek(const u32 pos);
    u32 r_tell() const {
        return r_pos;
    }

    void r(void* p, const size_t count) {
        VERIFY(p && count);
        std::memcpy(p, &B.data[r_pos], count);
        r_pos += count;
        VERIFY(r_pos <= B.count);
    }

    bool r_eof() const {
        return r_pos >= B.count;
    }

    u32 r_elapsed() const {
        return B.count - r_pos;
    }

    void r_advance(const u32 size);

    // reading - utilities
    void r_vec3(Fvector& A) {
        r(&A, sizeof(Fvector));
    }

    void r_vec4(Fvector4& A) {
        r(&A, sizeof(Fvector4));
    }

    void r_float(float& A) {
        r(&A, sizeof(float));
    }

    void r_u64(u64& A) {
        r(&A, sizeof(u64));
    }

    void r_s64(s64& A) {
        r(&A, sizeof(s64));
    }

    void r_u32(u32& A) {
        r(&A, sizeof(u32));
    }

    void r_s32(s32& A) {
        r(&A, sizeof(s32));
    }

    void r_u16(u16& A) {
        r(&A, sizeof(u16));
    }

    void r_s16(s16& A) {
        r(&A, sizeof(s16));
    }

    void r_u8(u8& A) {
        r(&A, sizeof(u8));
    }

    void r_s8(s8& A) {
        r(&A, sizeof(s8));
    }

    // IReader compatibility
    Fvector r_vec3();
    Fvector4 r_vec4();
    float r_float_q8(const float min, const float max);
    float r_float_q16(const float min, const float max);
    float r_float();
    u64 r_u64();
    s64 r_s64();
    u32 r_u32();
    s32 r_s32();
    u16 r_u16();
    s16 r_s16();
    u8 r_u8();
    s8 r_s8();

    void r_float_q16(float& A, const float min, const float max);
    void r_float_q8(float& A, const float min, const float max);
    void r_angle16(float& A);
    void r_angle8(float& A);
    void r_dir(Fvector& A);

    void r_sdir(Fvector& A);
    void r_stringZ(char* S);
    void r_stringZ(std::string& dest);
    void r_stringZ(shared_str& dest);

    void skip_stringZ();

    void r_stringZ_s(char* string, const size_t size);

    template <size_t size>
    void r_stringZ_s(char (&string)[size]) {
        r_stringZ_s(string, size);
    }

    void r_matrix(Fmatrix& M);
    void r_clientID(ClientID& C);
};
