#pragma once

#define ENGINE_API
#define ECORE_API

#ifdef _EDITOR
#include "skeletonX.h"
#include "skeletoncustom.h"
#else // _EDITOR
#include "../xrCore/xrCore.h"
#include "xrRenderCommon/SkeletonXVertRender.h"
#include "../xrEngine/bone.h"
#define RENDER 1
#include "../xrEngine/Render.h"
#include "../xrEngine/Device.h"
#include "xrRenderCommon/light.h"
#endif // _EDITOR

#include "xrCPU_Pipe.h"
#include "ttapi.h"
