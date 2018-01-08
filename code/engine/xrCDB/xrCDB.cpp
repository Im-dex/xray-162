// xrCDB.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#pragma hdrstop

#include "xrCDB.h"

namespace Opcode {
#include "OPC_TreeBuilders.h"
} // namespace Opcode

using namespace CDB;
using namespace Opcode;

BOOL APIENTRY DllMain(HANDLE hModule, u32 ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// Model building
MODEL::MODEL() {
    tree = 0;
    tris = 0;
    tris_count = 0;
    verts = 0;
    verts_count = 0;
    status = S_INIT;
}
MODEL::~MODEL() {
    syncronize(); // maybe model still in building
    status = S_INIT;
    CDELETE(tree);
    CFREE(tris);
    tris_count = 0;
    CFREE(verts);
    verts_count = 0;
}

void MODEL::build(Fvector* V, int Vcnt, TRI* T, int Tcnt, build_callback* bc, void* bcp) {
    R_ASSERT(S_INIT == status);
    R_ASSERT((Vcnt >= 4) && (Tcnt >= 2));

	build_internal(V, Vcnt, T, Tcnt, bc, bcp);
	status = S_READY;
}

void MODEL::build_internal(Fvector* V, int Vcnt, TRI* T, int Tcnt, build_callback* bc, void* bcp) {
    // verts
    verts_count = Vcnt;
    verts = CALLOC(Fvector, verts_count);
    std::memcpy(verts, V, verts_count * sizeof(Fvector));

    // tris
    tris_count = Tcnt;
    tris = CALLOC(TRI, tris_count);
    std::memcpy(tris, T, tris_count * sizeof(TRI));

    // callback
    if (bc)
        bc(verts, Vcnt, tris, Tcnt, bcp);

    // Release data pointers
    status = S_BUILD;

    // Allocate temporary "OPCODE" tris + convert tris to 'pointer' form
    u32* temp_tris = CALLOC(u32, tris_count * 3);
    if (0 == temp_tris) {
        CFREE(verts);
        CFREE(tris);
        return;
    }
    u32* temp_ptr = temp_tris;
    for (int i = 0; i < tris_count; i++) {
        *temp_ptr++ = tris[i].verts[0];
        *temp_ptr++ = tris[i].verts[1];
        *temp_ptr++ = tris[i].verts[2];
    }

    // Build a non quantized no-leaf tree
    OPCODECREATE OPCC;
    OPCC.NbTris = tris_count;
    OPCC.NbVerts = verts_count;
    OPCC.Tris = (unsigned*)temp_tris;
    OPCC.Verts = (Point*)verts;
    OPCC.Rules = SPLIT_COMPLETE | SPLIT_SPLATTERPOINTS | SPLIT_GEOMCENTER;
    OPCC.NoLeaf = true;
    OPCC.Quantized = false;
    // if (Memory.debug_mode) OPCC.KeepOriginal = true;

    tree = CNEW(OPCODE_Model)();
    if (!tree->Build(OPCC)) {
        CFREE(verts);
        CFREE(tris);
        CFREE(temp_tris);
        return;
    };

    // Free temporary tris
    CFREE(temp_tris);
    return;
}

u32 MODEL::memory() {
    if (S_BUILD == status) {
        Msg("! xrCDB: model still isn't ready");
        return 0;
    }
    u32 V = verts_count * sizeof(Fvector);
    u32 T = tris_count * sizeof(TRI);
    return tree->GetUsedBytes() + V + T + sizeof(*this) + sizeof(*tree);
}

// This is the constructor of a class that has been exported.
// see xrCDB.h for the class definition
COLLIDER::COLLIDER() {
    ray_mode = 0;
    box_mode = 0;
    frustum_mode = 0;
}

COLLIDER::~COLLIDER() { r_free(); }

RESULT& COLLIDER::r_add() {
    rd.push_back(RESULT());
    return rd.back();
}

void COLLIDER::r_free() { rd.clear(); }
