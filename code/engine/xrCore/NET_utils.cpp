#include "stdafx.h"
#pragma hdrstop
#include "NET_utils.h"

// ---NET_Packet
// reading

u32 NET_Packet::r_begin(u16& type) { // returns time of receiving
    r_pos = 0;
    r_u16(type);
    return timeReceive;
}

void NET_Packet::w_seek(const u32 pos, const void* p, const u32 count) {
    VERIFY(p && count && (pos + count <= B.count));
    std::memcpy(&B.data[pos], p, count);
}

void NET_Packet::r_seek(const u32 pos) {
    VERIFY(pos < B.count);
    r_pos = pos;
}

void NET_Packet::r_advance(const u32 size) {
    r_pos += size;
    VERIFY(r_pos <= B.count);
}

// reading - utilities

// IReader compatibility
Fvector NET_Packet::r_vec3() {
    Fvector A;
    r_vec3(A);
    return A;
}

Fvector4 NET_Packet::r_vec4() {
    Fvector4 A;
    r_vec4(A);
    return (A);
}

float NET_Packet::r_float_q8(const float min, const float max) {
    float A;
    r_float_q8(A, min, max);
    return A;
}

float NET_Packet::r_float_q16(const float min, const float max) {
    float A;
    r_float_q16(A, min, max);
    return A;
}

float NET_Packet::r_float() {
    float A;
    r_float(A);
    return A;
} // float

u64 NET_Packet::r_u64() {
    u64 A;
    r_u64(A);
    return (A);
} // qword (8b)

s64 NET_Packet::r_s64() {
    s64 A;
    r_s64(A);
    return (A);
} // qword (8b)

u32 NET_Packet::r_u32() {
    u32 A;
    r_u32(A);
    return (A);
} // dword (4b)

s32 NET_Packet::r_s32() {
    s32 A;
    r_s32(A);
    return (A);
} // dword (4b)

u16 NET_Packet::r_u16() {
    u16 A;
    r_u16(A);
    return (A);
} // word (2b)

s16 NET_Packet::r_s16() {
    s16 A;
    r_s16(A);
    return (A);
} // word (2b)

u8 NET_Packet::r_u8() {
    u8 A;
    r_u8(A);
    return (A);
} // byte (1b)

s8 NET_Packet::r_s8() {
    s8 A;
    r_s8(A);
    return (A);
}

void NET_Packet::r_float_q16(float& A, const float min, const float max) {
    u16 val;
    r_u16(val);
    A = (float(val) * (max - min)) / 65535.f + min; // floating-point-error possible
    VERIFY((A >= min - EPS_S) && (A <= max + EPS_S));
}

void NET_Packet::r_float_q8(float& A, const float min, const float max) {
    u8 val;
    r_u8(val);
    A = (float(val) / 255.0001f) * (max - min) + min; // floating-point-error possible
    VERIFY((A >= min) && (A <= max));
}

void NET_Packet::r_angle16(float& A) { r_float_q16(A, 0.f, PI_MUL_2); }

void NET_Packet::r_angle8(float& A) { r_float_q8(A, 0.f, PI_MUL_2); }

void NET_Packet::r_dir(Fvector& A) {
    u16 t;
    r_u16(t);
    pvDecompress(A, t);
}

void NET_Packet::r_sdir(Fvector& A) {
    u16 t;
    float s;
    r_u16(t);
    r_float(s);
    pvDecompress(A, t);
    A.mul(s);
}

void NET_Packet::r_stringZ(char* S) {
    const char* data = reinterpret_cast<const char*>(&B.data[r_pos]);
    const size_t len = xr_strlen(data);
    r(S, len + 1);
}

void NET_Packet::r_stringZ(xr_string& dest) {
    dest = reinterpret_cast<const char*>(&B.data[r_pos]);
    r_advance(u32(dest.size() + 1));
}

void NET_Packet::r_stringZ(shared_str& dest) {
    dest = reinterpret_cast<const char*>(&B.data[r_pos]);
    r_advance(dest.size() + 1);
}

void NET_Packet::skip_stringZ() {
    const char* data = reinterpret_cast<const char*>(&B.data[r_pos]);
    const auto len = xr_strlen(data);
    r_advance(len + 1);
}

void NET_Packet::r_matrix(Fmatrix& M) {
    r_vec3(M.i);
    M._14_ = 0;
    r_vec3(M.j);
    M._24_ = 0;
    r_vec3(M.k);
    M._34_ = 0;
    r_vec3(M.c);
    M._44_ = 1;
}

void NET_Packet::r_clientID(ClientID& C) {
    u32 tmp;
    r_u32(tmp);
    C.set(tmp);
}

void NET_Packet::r_stringZ_s(char* string, const size_t size) {
    auto data = reinterpret_cast<LPCSTR>(B.data) + r_pos;
    const size_t length = xr_strlen(data);
    R_ASSERT2((length + 1) <= size, "buffer overrun");
    r(string, length + 1);
}