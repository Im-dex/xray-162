// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once

#pragma warning(disable : 4995)
#include "xrEngine/stdafx.h"
#pragma warning(disable : 4995)
#include <d3dx9.h>
#pragma warning(default : 4995)
#pragma warning(disable : 4714)
#pragma warning(4 : 4018)
#pragma warning(4 : 4244)
#pragma warning(disable : 4237)

#include "xrRenderCommon/xrD3DDefs.h"

#include "xrRenderCommon/HW.h"
#include "xrRenderCommon/Shader.h"
#include "xrRenderCommon/R_Backend.h"
#include "xrRenderCommon/R_Backend_Runtime.h"

#define R_R1 1
#define R_R2 2
#define R_R3 3
#define R_R4 4
#define RENDER R_R2

#include "xrRenderCommon/resourcemanager.h"

#include "xrEngine/vis_common.h"
#include "xrEngine/render.h"
#include "xrEngine/_d3d_extensions.h"
#include "xrEngine/igame_level.h"
#include "xrRenderCommon/blenders\blender.h"
#include "xrRenderCommon/blenders\blender_clsid.h"
#include "xrParticles/psystem.h"
#include "xrRenderCommon/xrRender_console.h"
#include "r2.h"

IC void jitter(CBlender_Compile& C) {
    C.r_Sampler("jitter0", JITTER(0), true, D3DTADDRESS_WRAP, D3DTEXF_POINT, D3DTEXF_NONE,
                D3DTEXF_POINT);
    C.r_Sampler("jitter1", JITTER(1), true, D3DTADDRESS_WRAP, D3DTEXF_POINT, D3DTEXF_NONE,
                D3DTEXF_POINT);
    C.r_Sampler("jitter2", JITTER(2), true, D3DTADDRESS_WRAP, D3DTEXF_POINT, D3DTEXF_NONE,
                D3DTEXF_POINT);
    C.r_Sampler("jitter3", JITTER(3), true, D3DTADDRESS_WRAP, D3DTEXF_POINT, D3DTEXF_NONE,
                D3DTEXF_POINT);
    C.r_Sampler("jitter4", JITTER(4), true, D3DTADDRESS_WRAP, D3DTEXF_POINT, D3DTEXF_NONE,
                D3DTEXF_POINT);
}
