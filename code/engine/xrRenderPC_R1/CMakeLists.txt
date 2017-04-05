cmake_minimum_required(VERSION 3.8)

project(xrRender_R1)

set(INTERFASE_IMPLEMENTATIONS_STATGRAPHRENDER ../xrRenderCommon/dxStatGraphRender.h
                                              ../xrRender/StatGraphRender.h
                                              ../xrRenderCommon/dxStatGraphRender.cpp)

set(DETAILS ../xrRenderCommon/DetailFormat.h
            ../xrRenderCommon/DetailManager.h
            ../xrRenderCommon/DetailModel.h
            ../xrRenderCommon/DetailManager.cpp
            ../xrRenderCommon/DetailManager_CACHE.cpp
            ../xrRenderCommon/DetailManager_Decompress.cpp
            ../xrRenderCommon/DetailManager_soft.cpp
            ../xrRenderCommon/DetailManager_VS.cpp
            ../xrRenderCommon/DetailModel.cpp)

set(MODELS_VISUALS ../xrRenderCommon/FLOD.h
                   ../xrRenderCommon/FProgressive.h
                   ../xrRenderCommon/FSkinned.h
                   ../xrRenderCommon/FTreeVisual.h
                   ../xrRenderCommon/FVisual.h
                   ../xrRenderCommon/ParticleEffect.h
                   ../xrRenderCommon/ParticleEffectDef.h
                   ../xrRenderCommon/ParticleGroup.h
                   ../xrRenderCommon/FLOD.cpp
                   ../xrRenderCommon/FProgressive.cpp
                   ../xrRenderCommon/FSkinned.cpp
                   ../xrRenderCommon/FTreeVisual.cpp
                   ../xrRenderCommon/FVisual.cpp
                   ../xrRenderCommon/ParticleEffect.cpp
                   ../xrRenderCommon/ParticleEffectDef.cpp
                   ../xrRenderCommon/ParticleGroup.cpp)

set(KERNEL ../xrRenderCommon/cl_intersect.h
           stdafx.h
           ../xrRenderCommon/xrD3DDefs.h
           ../xrRenderCommon/xrRender_console.h
           stdafx.cpp
           ../xrRenderCommon/xrRender_console.cpp
           xrRender_R1.cpp)

set(INTERFASE_IMPLEMENTATIONS_WALLMARKARRAY ../xrRenderCommon/dxWallMarkArray.h
                                            ../xrRender/WallMarkArray.h
                                            ../xrRenderCommon/dxWallMarkArray.cpp)

set(GLOWS GlowManager.h
          GlowManager.cpp)

set(INTERFASE_IMPLEMENTATIONS_RENDERDEVICERENDER ../xrRenderCommon/dxRenderDeviceRender.h
                                                 ../xrRender/RenderDeviceRender.h
                                                 ../xrRenderCommon/dxRenderDeviceRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_CONSOLERENDER ../xrRender/ConsoleRender.h
                                            ../xrRenderCommon/dxConsoleRender.h
                                            ../xrRenderCommon/dxConsoleRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_THUNDERBOLTDESCRENDER ../xrRenderCommon/dxThunderboltDescRender.h
                                                    ../xrRender/ThunderboltDescRender.h
                                                    ../xrRenderCommon/dxThunderboltDescRender.cpp)

set(LIGHTS ../xrRenderCommon/light.h
           ../xrRenderCommon/Light_DB.h
           ../xrRenderCommon/Light_Package.h
           LightPPA.h
           LightProjector.h
           LightShadows.h
           ../xrRenderCommon/light.cpp
           ../xrRenderCommon/Light_DB.cpp
           ../xrRenderCommon/Light_Package.cpp
           LightPPA.cpp
           LightProjector.cpp
           LightShadows.cpp
           ../xrRenderCommon/LightTrack.cpp)

set(REFACTORED_EXECUTION__AND__3D_SHADERS_BLENDER ../xrRenderCommon/blenders/Blender.h
                                                  ../xrRenderCommon/blenders/Blender_CLSID.h
                                                  ../xrRenderCommon/blenders/Blender_Recorder.h
                                                  ../xrRenderCommon/tss.h
                                                  ../xrRenderCommon/tss_def.h
                                                  ../xrRenderCommon/blenders/Blender.cpp
                                                  ../xrRenderCommon/blenders/Blender_Palette.cpp
                                                  ../xrRenderCommon/blenders/Blender_Recorder.cpp
                                                  ../xrRenderCommon/Blender_Recorder_R2.cpp
                                                  ../xrRenderCommon/Blender_Recorder_StandartBinding.cpp
                                                  ../xrRenderCommon/tss_def.cpp)

set(REFACTORED_INTERFACES ../xrRenderCommon/IRenderDetailModel.h
                          ../xrRender/RenderDetailModel.h)

set(INTERFASE_IMPLEMENTATIONS_STATSRENDER ../xrRenderCommon/dxStatsRender.h
                                          ../xrRender/StatsRender.h
                                          ../xrRenderCommon/dxStatsRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_RENDERFACTORY ../xrRenderCommon/dxRenderFactory.h
                                            ../xrRender/RenderFactory.h
                                            ../xrRenderCommon/dxRenderFactory.cpp)

set(INTERFASE_IMPLEMENTATIONS_DEBUG ../xrRender/DebugShader.h)

set(VISIBILITY_HOM_OCCLUSION ../xrRenderCommon/HOM.h
                             ../xrRenderCommon/occRasterizer.h
                             ../xrRenderCommon/HOM.cpp
                             ../xrRenderCommon/occRasterizer.cpp
                             ../xrRenderCommon/occRasterizer_core.cpp)

set(MODELS ../xrRenderCommon/LightTrack.h
           ../xrRenderCommon/ModelPool.h
           ../xrRenderCommon/ModelPool.cpp)

set(INTERFASE_IMPLEMENTATIONS_ENVIRONMENTRENDER ../xrRenderCommon/dxEnvironmentRender.h
                                                ../xrRender/EnvironmentRender.h
                                                ../xrRenderCommon/dxEnvironmentRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_LENSFLARE ../xrRenderCommon/dxLensFlareRender.h
                                        ../xrRender/LensFlareRender.h
                                        ../xrRenderCommon/dxLensFlareRender.cpp)

set(REFACTORED_BACKEND ../xrRenderDX9/dx9R_Backend_Runtime.h
                       ../xrRenderCommon/FVF.h
                       ../xrRenderCommon/R_Backend.h
                       ../xrRenderCommon/R_Backend_hemi.h
                       ../xrRenderCommon/R_Backend_Runtime.h
                       ../xrRenderCommon/R_Backend_tree.h
                       ../xrRenderCommon/R_Backend_xform.h
                       ../xrRenderCommon/R_DStreams.h
                       ../xrRenderCommon/R_Backend.cpp
                       ../xrRenderCommon/R_Backend_DBG.cpp
                       ../xrRenderCommon/R_Backend_hemi.cpp
                       ../xrRenderCommon/R_Backend_Runtime.cpp
                       ../xrRenderCommon/R_Backend_tree.cpp
                       ../xrRenderCommon/R_Backend_xform.cpp
                       ../xrRenderCommon/R_DStreams.cpp)

set(WALLMARKS ../xrRenderCommon/WallmarksEngine.h
              ../xrRenderCommon/WallmarksEngine.cpp)

set(INTERFASE_IMPLEMENTATIONS_UI_UISHADER ../xrRenderCommon/dxUIShader.h
                                          ../xrRender/UIShader.h
                                          ../xrRenderCommon/dxUIShader.cpp)

set(CORE_COLORMAP ../xrRenderCommon/ColorMapManager.h
                  ../xrRenderCommon/ColorMapManager.cpp)

set(VISIBILITY_SECTOR_PORTAL ../xrRenderCommon/r__sector.h
                             ../xrRenderCommon/r__sector.cpp
                             ../xrRenderCommon/r__sector_traversal.cpp)

set(INTERFASE_IMPLEMENTATIONS_UI_UISEQUENCEVIDEOITEM ../xrRenderCommon/dxUISequenceVideoItem.h
                                                     ../xrRender/UISequenceVideoItem.h
                                                     ../xrRenderCommon/dxUISequenceVideoItem.cpp)

set(INTERFASE_IMPLEMENTATIONS_APPLICATIONRENDER ../xrRender/ApplicationRender.h
                                                ../xrRenderCommon/dxApplicationRender.h
                                                ../xrRenderCommon/dxApplicationRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_THUNDERBOLTRENDER ../xrRenderCommon/dxThunderboltRender.h
                                                ../xrRender/ThunderboltRender.h
                                                ../xrRenderCommon/dxThunderboltRender.cpp)

set(REFACTORED_STATS_MANAGER ../xrRenderCommon/stats_manager.h
                             ../xrRenderCommon/stats_manager.cpp)

set(REFACTORED_HW ../xrRenderCommon/HW.h
                  ../xrRenderCommon/HWCaps.h
                  ../xrRenderCommon/HW.cpp
                  ../xrRenderCommon/HWCaps.cpp)

set(REFACTORED_EXECUTION__AND__3D_VISUALS_SKELETON ../xrRenderCommon/Animation.h
                                                   ../xrRender/animation_blend.h
                                                   ../xrRender/animation_motion.h
                                                   ../xrRenderCommon/AnimationKeyCalculate.h
                                                   ../xrRenderCommon/KinematicAnimatedDefs.h
                                                   ../xrRender/Kinematics.h
                                                   ../xrRender/KinematicsAnimated.h
                                                   ../xrRenderCommon/SkeletonAnimated.h
                                                   ../xrRenderCommon/SkeletonCustom.h
                                                   ../xrRenderCommon/SkeletonX.h
                                                   ../xrRenderCommon/SkeletonXVertRender.h
                                                   ../xrRenderCommon/Animation.cpp
                                                   ../xrRenderCommon/SkeletonAnimated.cpp
                                                   ../xrRenderCommon/SkeletonCustom.cpp
                                                   ../xrRenderCommon/SkeletonRigid.cpp
                                                   ../xrRenderCommon/SkeletonX.cpp)

set(REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES_DX9_R_SHADER ../xrRenderDX9/dx9r_constants_cache.h
                                                                 ../xrRenderCommon/r_constants_cache.h
                                                                 ../xrRenderDX9/dx9r_constants_cache.cpp)

set(INTERFASE_IMPLEMENTATIONS_FONTRENDER ../xrRenderCommon/dxFontRender.h
                                         ../xrRender/FontRender.h
                                         ../xrRenderCommon/dxFontRender.cpp)

set(REFACTORED_EXECUTION__AND__3D_DEBUGDRAW ../xrRenderCommon/D3DUtils.h
                                            ../xrRender/DrawUtils.h
                                            ../xrRenderCommon/du_box.h
                                            ../xrRenderCommon/du_cone.h
                                            ../xrRenderCommon/du_cylinder.h
                                            ../xrRenderCommon/du_sphere.h
                                            ../xrRenderCommon/du_sphere_part.h
                                            ../xrRenderCommon/D3DUtils.cpp
                                            ../xrRenderCommon/du_box.cpp
                                            ../xrRenderCommon/du_cone.cpp
                                            ../xrRenderCommon/du_cylinder.cpp
                                            ../xrRenderCommon/du_sphere.cpp
                                            ../xrRenderCommon/du_sphere_part.cpp)

set(REFACTORED_EXECUTION__AND__3D_VISUALS ../xrRenderCommon/dxParticleCustom.h
                                          ../xrRenderCommon/FBasicVisual.h
                                          ../xrRenderCommon/FHierrarhyVisual.h
                                          ../xrRender/ParticleCustom.h
                                          ../xrRender/RenderVisual.h
                                          ../xrRenderCommon/dxParticleCustom.cpp
                                          ../xrRenderCommon/FBasicVisual.cpp
                                          ../xrRenderCommon/FHierrarhyVisual.cpp)

set(STRIPIFIER ../xrRenderCommon/NvTriStrip.h
               ../xrRenderCommon/NvTriStripObjects.h
               ../xrRenderCommon/VertexCache.h
               ../xrRenderCommon/xrStripify.h
               ../xrRenderCommon/NvTriStrip.cpp
               ../xrRenderCommon/NvTriStripObjects.cpp
               ../xrRenderCommon/VertexCache.cpp
               ../xrRenderCommon/xrStripify.cpp)

set(INTERFASE_IMPLEMENTATIONS_FACTORYPTR ../xrRender/FactoryPtr.h)

set(REFACTORED_EXECUTION__AND__3D_SHADERS_SHADERMANAGER ../xrRenderCommon/ETextureParams.h
                                                        ../xrRenderCommon/ResourceManager.h
                                                        ../xrRenderCommon/TextureDescrManager.h
                                                        ../xrEngine/ai_script_lua_debug.cpp
                                                        ../xrEngine/ai_script_lua_extension.cpp
                                                        ../xrRenderCommon/ETextureParams.cpp
                                                        ../xrRenderCommon/ResourceManager.cpp
                                                        ../xrRenderCommon/ResourceManager_Loader.cpp
                                                        ../xrRenderCommon/ResourceManager_Reset.cpp
                                                        ../xrRenderCommon/ResourceManager_Resources.cpp
                                                        ../xrRenderCommon/ResourceManager_Scripting.cpp
                                                        ../xrRenderCommon/TextureDescrManager.cpp)

set(CORE FStaticRender.h
         FStaticRender_RenderTarget.h
         ../xrRenderCommon/PSLibrary.h
         ../xrRenderCommon/r__dsgraph_structure.h
         ../xrRenderCommon/r__dsgraph_types.h
         FStaticRender.cpp
         FStaticRender_Blenders.cpp
         FStaticRender_DetectSector.cpp
         FStaticRender_Loader.cpp
         FStaticRender_RenderTarget.cpp
         ../xrRenderCommon/PSLibrary.cpp
         ../xrRenderCommon/r__dsgraph_build.cpp
         ../xrRenderCommon/r__dsgraph_render.cpp
         ../xrRenderCommon/r__dsgraph_render_lods.cpp
         ../xrRenderCommon/r__screenshot.cpp
         ../xrRenderCommon/Texture.cpp
         ../xrRenderCommon/tga.cpp)

set(REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES ../xrRenderCommon/r_constants.h
                                                    ../xrRenderCommon/SH_Atomic.h
                                                    ../xrRenderCommon/SH_Constant.h
                                                    ../xrRenderCommon/SH_Matrix.h
                                                    ../xrRenderCommon/SH_RT.h
                                                    ../xrRenderCommon/SH_Texture.h
                                                    ../xrRenderCommon/Shader.h
                                                    ../xrRenderCommon/r_constants.cpp
                                                    ../xrRenderCommon/SH_Atomic.cpp
                                                    ../xrRenderCommon/SH_Constant.cpp
                                                    ../xrRenderCommon/SH_Matrix.cpp
                                                    ../xrRenderCommon/SH_RT.cpp
                                                    ../xrRenderCommon/SH_Texture.cpp
                                                    ../xrRenderCommon/Shader.cpp)

set(INTERFASE_IMPLEMENTATIONS_OBJECTSPACERENDER ../xrRenderCommon/dxObjectSpaceRender.h
                                                ../xrRender/ObjectSpaceRender.h
                                                ../xrRenderCommon/dxObjectSpaceRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_RAINRENDER ../xrRenderCommon/dxRainRender.h
                                         ../xrRender/RainRender.h
                                         ../xrRenderCommon/dxRainRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_UI_UIRENDER ../xrRenderCommon/dxUIRender.h
                                          ../xrRender/UIRender.h
                                          ../xrRenderCommon/dxUIRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_DEBUG_DEBUGRENDER ../xrRender/DebugRender.h
                                                ../xrRenderCommon/dxDebugRender.h
                                                ../xrRenderCommon/dxDebugRender.cpp)

set(REFACTORED_EXECUTION__AND__3D_GAMMA ../xrRenderCommon/xr_effgamma.h
                                        ../xrRenderCommon/xr_effgamma.cpp)

set(SHADING_TEMPLATES Blender_Blur.h
                      ../xrRenderCommon/Blender_BmmD.h
                      Blender_default_aref.h
                      ../xrRenderCommon/Blender_detail_still.h
                      ../xrRenderCommon/Blender_Editor_Selection.h
                      ../xrRenderCommon/Blender_Editor_Wire.h
                      Blender_LaEmB.h
                      "../xrRenderCommon/Blender_Lm(EbB).h"
                      Blender_Model.h
                      ../xrRenderCommon/Blender_Model_EbB.h
                      ../xrRenderCommon/Blender_Particle.h
                      Blender_Screen_GRAY.h
                      ../xrRenderCommon/Blender_Screen_SET.h
                      Blender_Shadow_World.h
                      ../xrRenderCommon/Blender_tree.h
                      Blender_Vertex.h
                      Blender_Vertex_aref.h
                      BlenderDefault.h
                      Blender_Blur.cpp
                      ../xrRenderCommon/Blender_BmmD.cpp
                      Blender_default_aref.cpp
                      ../xrRenderCommon/Blender_detail_still.cpp
                      ../xrRenderCommon/Blender_Editor_Selection.cpp
                      ../xrRenderCommon/Blender_Editor_Wire.cpp
                      Blender_LaEmB.cpp
                      "../xrRenderCommon/Blender_Lm(EbB).cpp"
                      Blender_Model.cpp
                      ../xrRenderCommon/Blender_Model_EbB.cpp
                      ../xrRenderCommon/Blender_Particle.cpp
                      Blender_Screen_GRAY.cpp
                      ../xrRenderCommon/Blender_Screen_SET.cpp
                      Blender_Shadow_World.cpp
                      ../xrRenderCommon/Blender_tree.cpp
                      Blender_Vertex.cpp
                      Blender_Vertex_aref.cpp
                      BlenderDefault.cpp)

source_group("Interfase implementations\\StatGraphRender" FILES ${INTERFASE_IMPLEMENTATIONS_STATGRAPHRENDER})
source_group("Details" FILES ${DETAILS})
source_group("Models\\Visuals" FILES ${MODELS_VISUALS})
source_group("Kernel" FILES ${KERNEL})
source_group("Interfase implementations\\WallMarkArray" FILES ${INTERFASE_IMPLEMENTATIONS_WALLMARKARRAY})
source_group("Glows" FILES ${GLOWS})
source_group("Interfase implementations\\RenderDeviceRender" FILES ${INTERFASE_IMPLEMENTATIONS_RENDERDEVICERENDER})
source_group("Interfase implementations\\ConsoleRender" FILES ${INTERFASE_IMPLEMENTATIONS_CONSOLERENDER})
source_group("Interfase implementations\\ThunderboltDescRender" FILES ${INTERFASE_IMPLEMENTATIONS_THUNDERBOLTDESCRENDER})
source_group("Lights" FILES ${LIGHTS})
source_group("Refactored\\Execution &amp; 3D\\Shaders\\Blender" FILES ${REFACTORED_EXECUTION__AND__3D_SHADERS_BLENDER})
source_group("Refactored\\Interfaces" FILES ${REFACTORED_INTERFACES})
source_group("Interfase implementations\\StatsRender" FILES ${INTERFASE_IMPLEMENTATIONS_STATSRENDER})
source_group("Interfase implementations\\RenderFactory" FILES ${INTERFASE_IMPLEMENTATIONS_RENDERFACTORY})
source_group("Interfase implementations\\Debug" FILES ${INTERFASE_IMPLEMENTATIONS_DEBUG})
source_group("Visibility\\HOM Occlusion" FILES ${VISIBILITY_HOM_OCCLUSION})
source_group("Models" FILES ${MODELS})
source_group("Interfase implementations\\EnvironmentRender" FILES ${INTERFASE_IMPLEMENTATIONS_ENVIRONMENTRENDER})
source_group("Interfase implementations\\LensFlare" FILES ${INTERFASE_IMPLEMENTATIONS_LENSFLARE})
source_group("Refactored\\Backend" FILES ${REFACTORED_BACKEND})
source_group("Wallmarks" FILES ${WALLMARKS})
source_group("Interfase implementations\\UI\\UIShader" FILES ${INTERFASE_IMPLEMENTATIONS_UI_UISHADER})
source_group("Core\\ColorMap" FILES ${CORE_COLORMAP})
source_group("Visibility\\Sector/Portal" FILES ${VISIBILITY_SECTOR_PORTAL})
source_group("Interfase implementations\\UI\\UISequenceVideoItem" FILES ${INTERFASE_IMPLEMENTATIONS_UI_UISEQUENCEVIDEOITEM})
source_group("Interfase implementations\\ApplicationRender" FILES ${INTERFASE_IMPLEMENTATIONS_APPLICATIONRENDER})
source_group("Interfase implementations\\ThunderboltRender" FILES ${INTERFASE_IMPLEMENTATIONS_THUNDERBOLTRENDER})
source_group("Refactored\\stats_manager" FILES ${REFACTORED_STATS_MANAGER})
source_group("Refactored\\HW" FILES ${REFACTORED_HW})
source_group("Refactored\\Execution &amp; 3D\\Visuals\\Skeleton" FILES ${REFACTORED_EXECUTION__AND__3D_VISUALS_SKELETON})
source_group("Refactored\\Execution &amp; 3D\\Shaders\\Resources\\dx9_R_shader" FILES ${REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES_DX9_R_SHADER})
source_group("Interfase implementations\\FontRender" FILES ${INTERFASE_IMPLEMENTATIONS_FONTRENDER})
source_group("Refactored\\Execution &amp; 3D\\DebugDraw" FILES ${REFACTORED_EXECUTION__AND__3D_DEBUGDRAW})
source_group("Refactored\\Execution &amp; 3D\\Visuals" FILES ${REFACTORED_EXECUTION__AND__3D_VISUALS})
source_group("Stripifier" FILES ${STRIPIFIER})
source_group("Interfase implementations\\FactoryPtr" FILES ${INTERFASE_IMPLEMENTATIONS_FACTORYPTR})
source_group("Refactored\\Execution &amp; 3D\\Shaders\\ShaderManager" FILES ${REFACTORED_EXECUTION__AND__3D_SHADERS_SHADERMANAGER})
source_group("Core" FILES ${CORE})
source_group("Refactored\\Execution &amp; 3D\\Shaders\\Resources" FILES ${REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES})
source_group("Interfase implementations\\ObjectSpaceRender" FILES ${INTERFASE_IMPLEMENTATIONS_OBJECTSPACERENDER})
source_group("Interfase implementations\\RainRender" FILES ${INTERFASE_IMPLEMENTATIONS_RAINRENDER})
source_group("Interfase implementations\\UI\\UIRender" FILES ${INTERFASE_IMPLEMENTATIONS_UI_UIRENDER})
source_group("Interfase implementations\\Debug\\DebugRender" FILES ${INTERFASE_IMPLEMENTATIONS_DEBUG_DEBUGRENDER})
source_group("Refactored\\Execution &amp; 3D\\Gamma" FILES ${REFACTORED_EXECUTION__AND__3D_GAMMA})
source_group("Shading templates" FILES ${SHADING_TEMPLATES})

include_directories($ENV{DXSDK_DIR}/Include ../../3rd-party/luajit/include)
link_directories($ENV{DXSDK_DIR}/lib/x86 ../../lib)
add_definitions(-DATIMGPUD_DLL -DXRRENDER_R1_EXPORTS -D_SECURE_SCL=0)

add_compile_options(/fp:fast /GR "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrRender_R1 SHARED ${INTERFASE_IMPLEMENTATIONS_LENSFLARE}
                               ${WALLMARKS}
                               ${INTERFASE_IMPLEMENTATIONS_CONSOLERENDER}
                               ${INTERFASE_IMPLEMENTATIONS_DEBUG}
                               ${INTERFASE_IMPLEMENTATIONS_UI_UISHADER}
                               ${REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES}
                               ${REFACTORED_EXECUTION__AND__3D_VISUALS_SKELETON}
                               ${CORE}
                               ${INTERFASE_IMPLEMENTATIONS_STATGRAPHRENDER}
                               ${REFACTORED_EXECUTION__AND__3D_GAMMA}
                               ${GLOWS}
                               ${INTERFASE_IMPLEMENTATIONS_FACTORYPTR}
                               ${REFACTORED_BACKEND}
                               ${DETAILS}
                               ${VISIBILITY_HOM_OCCLUSION}
                               ${VISIBILITY_SECTOR_PORTAL}
                               ${INTERFASE_IMPLEMENTATIONS_DEBUG_DEBUGRENDER}
                               ${REFACTORED_EXECUTION__AND__3D_VISUALS}
                               ${INTERFASE_IMPLEMENTATIONS_STATSRENDER}
                               ${REFACTORED_HW}
                               ${INTERFASE_IMPLEMENTATIONS_APPLICATIONRENDER}
                               ${SHADING_TEMPLATES}
                               ${REFACTORED_EXECUTION__AND__3D_SHADERS_BLENDER}
                               ${INTERFASE_IMPLEMENTATIONS_UI_UIRENDER}
                               ${REFACTORED_EXECUTION__AND__3D_SHADERS_SHADERMANAGER}
                               ${STRIPIFIER}
                               ${INTERFASE_IMPLEMENTATIONS_RENDERDEVICERENDER}
                               ${REFACTORED_EXECUTION__AND__3D_DEBUGDRAW}
                               ${LIGHTS}
                               ${REFACTORED_INTERFACES}
                               ${KERNEL}
                               ${INTERFASE_IMPLEMENTATIONS_ENVIRONMENTRENDER}
                               ${INTERFASE_IMPLEMENTATIONS_FONTRENDER}
                               ${CORE_COLORMAP}
                               ${MODELS_VISUALS}
                               ${INTERFASE_IMPLEMENTATIONS_RAINRENDER}
                               ${INTERFASE_IMPLEMENTATIONS_OBJECTSPACERENDER}
                               ${INTERFASE_IMPLEMENTATIONS_THUNDERBOLTRENDER}
                               ${INTERFASE_IMPLEMENTATIONS_THUNDERBOLTDESCRENDER}
                               ${MODELS}
                               ${INTERFASE_IMPLEMENTATIONS_WALLMARKARRAY}
                               ${INTERFASE_IMPLEMENTATIONS_RENDERFACTORY}
                               ${INTERFASE_IMPLEMENTATIONS_UI_UISEQUENCEVIDEOITEM}
                               ${REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES_DX9_R_SHADER}
                               ${REFACTORED_STATS_MANAGER})
target_link_libraries(xrRender_R1 nvapi d3dx9 xrEngine xrCPU_Pipe xrParticles xrAPI)