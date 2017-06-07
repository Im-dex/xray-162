// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once

#pragma warning(disable:4995)
#include "xrEngine/stdafx.h"
#pragma warning(disable:4995)
#include <d3dx9.h>
#pragma warning(default:4995)
#pragma warning(disable:4714)
#pragma warning( 4 : 4018 )
#pragma warning( 4 : 4244 )

#include "xrRenderCommon/xrD3DDefs.h"

#include "xrRenderCommon/HW.h"
#include "xrRenderCommon/Shader.h"
#include "xrRenderCommon/R_Backend.h"
#include "xrRenderCommon/R_Backend_Runtime.h"

#define		R_R1	1
#define		R_R2	2
#define		R_R3	3
#define		R_R4	4
#define		RENDER	R_R1

#include "xrRenderCommon/resourcemanager.h"

#include "xrEngine/vis_common.h"
#include "xrEngine/render.h"
#include "xrEngine/_d3d_extensions.h"

#ifndef _EDITOR
#include "xrEngine/igame_level.h"

#include "xrRenderCommon/blenders\blender.h"
#include "xrRenderCommon/blenders\blender_clsid.h"
#include "xrParticles/psystem.h"
#include "xrRenderCommon/xrRender_console.h"
#include "FStaticRender.h"
#endif

#define		TEX_POINT_ATT	"internal\\internal_light_attpoint"
#define		TEX_SPOT_ATT	"internal\\internal_light_attclip"

