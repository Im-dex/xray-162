cmake_minimum_required(VERSION 3.8)

project(xrRender_R2)

set(INTERFASE_IMPLEMENTATIONS_STATGRAPHRENDER ../xrRenderCommon/dxStatGraphRender.h
                                              ../xrRender/StatGraphRender.h
                                              ../xrRenderCommon/dxStatGraphRender.cpp)

set(CORE_TARGET r2_rendertarget.h
                r2_rendertarget_wallmarks.h
                r2_rendertarget.cpp
                r2_rendertarget_accum_direct.cpp
                r2_rendertarget_accum_omnipart_geom.cpp
                r2_rendertarget_accum_point.cpp
                r2_rendertarget_accum_point_geom.cpp
                r2_rendertarget_accum_reflected.cpp
                r2_rendertarget_accum_spot.cpp
                r2_rendertarget_accum_spot_geom.cpp
                r2_rendertarget_draw_volume.cpp
                r2_rendertarget_enable_scissor.cpp
                r2_rendertarget_phase_accumulator.cpp
                r2_rendertarget_phase_bloom.cpp
                r2_rendertarget_phase_combine.cpp
                r2_rendertarget_phase_luminance.cpp
                r2_rendertarget_phase_occq.cpp
                r2_rendertarget_phase_PP.cpp
                r2_rendertarget_phase_scene.cpp
                r2_rendertarget_phase_smap_D.cpp
                r2_rendertarget_phase_smap_S.cpp
                r2_rendertarget_phase_ssao.cpp)

set(DETAILS ../xrRenderCommon/DetailManager.h
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

set(KERNEL stdafx.h
           ../xrRenderCommon/xrD3DDefs.h
           ../xrRenderCommon/xrRender_console.h
           stdafx.cpp
           ../xrRenderCommon/xrRender_console.cpp
           xrRender_R2.cpp)

set(INTERFASE_IMPLEMENTATIONS_WALLMARKARRAY ../xrRenderCommon/dxWallMarkArray.h
                                            ../xrRender/WallMarkArray.h
                                            ../xrRenderCommon/dxWallMarkArray.cpp)

set(CORE_TARGET_COLORMAP ../xrRenderCommon/ColorMapManager.h
                         ../xrRenderCommon/ColorMapManager.cpp)

set(INTERFASE_IMPLEMENTATIONS_RENDERDEVICERENDER ../xrRenderCommon/dxRenderDeviceRender.h
                                                 ../xrRender/RenderDeviceRender.h
                                                 ../xrRenderCommon/dxRenderDeviceRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_THUNDERBOLTDESCRENDER ../xrRenderCommon/dxThunderboltDescRender.h
                                                    ../xrRender/ThunderboltDescRender.h
                                                    ../xrRenderCommon/dxThunderboltDescRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_CONSOLERENDER ../xrRender/ConsoleRender.h
                                            ../xrRenderCommon/dxConsoleRender.h
                                            ../xrRenderCommon/dxConsoleRender.cpp)

set(LIGHTS ../xrRenderCommon/Light_DB.h
           light_gi.h
           ../xrRenderCommon/Light_Package.h
           Light_Render_Direct.h
           light_smapvis.h
           ../xrRenderCommon/LightTrack.h
           SMAP_Allocator.h
           ../xrRenderCommon/light.cpp
           ../xrRenderCommon/Light_DB.cpp
           light_GI.cpp
           ../xrRenderCommon/Light_Package.cpp
           Light_Render_Direct.cpp
           Light_Render_Direct_ComputeXFS.cpp
           light_smapvis.cpp
           light_vis.cpp
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

set(INTERFASE_IMPLEMENTATIONS_ENVIRONMENTRENDER ../xrRenderCommon/dxEnvironmentRender.h
                                                ../xrRender/EnvironmentRender.h
                                                ../xrRenderCommon/dxEnvironmentRender.cpp)

set(MODELS ../xrRenderCommon/ModelPool.h
           ../xrRenderCommon/ModelPool.cpp)

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

set(VISIBILITY_SECTOR_PORTAL ../xrRenderCommon/r__sector.h
                             ../xrRenderCommon/r__sector.cpp
                             ../xrRenderCommon/r__sector_traversal.cpp)

set(INTERFASE_IMPLEMENTATIONS_UI_UISEQUENCEVIDEOITEM ../xrRenderCommon/dxUISequenceVideoItem.h
                                                     ../xrRender/UISequenceVideoItem.h
                                                     ../xrRenderCommon/dxUISequenceVideoItem.cpp)

set(INTERFASE_IMPLEMENTATIONS_THUNDERBOLTRENDER ../xrRenderCommon/dxThunderboltRender.h
                                                ../xrRender/ThunderboltRender.h
                                                ../xrRenderCommon/dxThunderboltRender.cpp)

set(INTERFASE_IMPLEMENTATIONS_APPLICATIONRENDER ../xrRender/ApplicationRender.h
                                                ../xrRenderCommon/dxApplicationRender.h
                                                ../xrRenderCommon/dxApplicationRender.cpp)

set(REFACTORED_STATS_MANAGER ../xrRenderCommon/stats_manager.h
                             ../xrRenderCommon/stats_manager.cpp)

set(REFACTORED_HW ../xrRenderCommon/HW.h
                  ../xrRenderCommon/HWCaps.h
                  ../xrRenderCommon/HW.cpp
                  ../xrRenderCommon/HWCaps.cpp)

set(REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES_DX9_R_SHADER ../xrRenderDX9/dx9r_constants_cache.h
                                                                 ../xrRenderCommon/r_constants_cache.h
                                                                 ../xrRenderDX9/dx9r_constants_cache.cpp)

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
                                                   ../xrRenderCommon/Animation.cpp
                                                   ../xrRenderCommon/SkeletonAnimated.cpp
                                                   ../xrRenderCommon/SkeletonCustom.cpp
                                                   ../xrRenderCommon/SkeletonRigid.cpp
                                                   ../xrRenderCommon/SkeletonX.cpp)

set(INTERFASE_IMPLEMENTATIONS_FONTRENDER ../xrRenderCommon/dxFontRender.h
                                         ../xrRender/FontRender.h
                                         ../xrRenderCommon/dxFontRender.cpp)

set(SHADING_TEMPLATES_R1 ../xrRenderCommon/Blender_detail_still.h
                         "../xrRenderCommon/Blender_Lm(EbB).h"
                         ../xrRenderCommon/Blender_Model_EbB.h
                         ../xrRenderCommon/Blender_Screen_SET.h
                         ../xrRenderCommon/Blender_tree.h
                         ../xrRenderCommon/Blender_detail_still.cpp
                         "../xrRenderCommon/Blender_Lm(EbB).cpp"
                         ../xrRenderCommon/Blender_Model_EbB.cpp
                         ../xrRenderCommon/Blender_Screen_SET.cpp
                         ../xrRenderCommon/Blender_tree.cpp)

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

set(ROOT_SPECIAL_CONV todo.txt)

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

set(CORE ../xrRenderCommon/PSLibrary.h
         r2.h
         r2_types.h
         ../xrRenderCommon/r__dsgraph_structure.h
         ../xrRenderCommon/r__dsgraph_types.h
         ../xrRenderCommon/r__occlusion.h
         ../xrRenderCommon/r__pixel_calculator.h
         ../xrRenderCommon/r_sun_cascades.h
         ../xrRenderCommon/PSLibrary.cpp
         r2.cpp
         r2_blenders.cpp
         r2_loader.cpp
         r2_R_calculate.cpp
         r2_R_lights.cpp
         r2_R_render.cpp
         r2_R_sun.cpp
         r2_sector_detect.cpp
         r2_test_hw.cpp
         ../xrRenderCommon/r__dsgraph_build.cpp
         ../xrRenderCommon/r__dsgraph_render.cpp
         ../xrRenderCommon/r__dsgraph_render_lods.cpp
         ../xrRenderCommon/r__occlusion.cpp
         ../xrRenderCommon/r__pixel_calculator.cpp
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

set(SHADING_TEMPLATES blender_bloom_build.h
                      ../xrRenderCommon/Blender_BmmD.h
                      blender_combine.h
                      blender_deffer_aref.h
                      blender_deffer_flat.h
                      blender_deffer_model.h
                      ../xrRenderCommon/Blender_Editor_Selection.h
                      ../xrRenderCommon/Blender_Editor_Wire.h
                      blender_light_direct.h
                      blender_light_direct_cascade.h
                      blender_light_mask.h
                      blender_light_occq.h
                      blender_light_point.h
                      blender_light_reflected.h
                      blender_light_spot.h
                      blender_luminance.h
                      ../xrRenderCommon/Blender_Particle.h
                      blender_ssao.h
                      ../xrRenderCommon/uber_deffer.h
                      blender_bloom_build.cpp
                      ../xrRenderCommon/Blender_BmmD.cpp
                      blender_combine.cpp
                      blender_deffer_aref.cpp
                      blender_deffer_flat.cpp
                      blender_deffer_model.cpp
                      ../xrRenderCommon/Blender_Editor_Selection.cpp
                      ../xrRenderCommon/Blender_Editor_Wire.cpp
                      blender_light_direct.cpp
                      blender_light_direct_cascade.cpp
                      blender_light_mask.cpp
                      blender_light_occq.cpp
                      blender_light_point.cpp
                      blender_light_reflected.cpp
                      blender_light_spot.cpp
                      blender_luminance.cpp
                      ../xrRenderCommon/Blender_Particle.cpp
                      blender_ssao.cpp
                      ../xrRenderCommon/uber_deffer.cpp)

set(REFACTORED_EXECUTION__AND__3D_GAMMA ../xrRenderCommon/xr_effgamma.h
                                        ../xrRenderCommon/xr_effgamma.cpp)

source_group("Interfase implementations\\StatGraphRender" FILES ${INTERFASE_IMPLEMENTATIONS_STATGRAPHRENDER})
source_group("Core_Target" FILES ${CORE_TARGET})
source_group("Details" FILES ${DETAILS})
source_group("Models\\Visuals" FILES ${MODELS_VISUALS})
source_group("Kernel" FILES ${KERNEL})
source_group("Interfase implementations\\WallMarkArray" FILES ${INTERFASE_IMPLEMENTATIONS_WALLMARKARRAY})
source_group("Core_Target\\ColorMap" FILES ${CORE_TARGET_COLORMAP})
source_group("Interfase implementations\\RenderDeviceRender" FILES ${INTERFASE_IMPLEMENTATIONS_RENDERDEVICERENDER})
source_group("Interfase implementations\\ThunderboltDescRender" FILES ${INTERFASE_IMPLEMENTATIONS_THUNDERBOLTDESCRENDER})
source_group("Interfase implementations\\ConsoleRender" FILES ${INTERFASE_IMPLEMENTATIONS_CONSOLERENDER})
source_group("Lights" FILES ${LIGHTS})
source_group("Refactored\\Execution &amp; 3D\\Shaders\\Blender" FILES ${REFACTORED_EXECUTION__AND__3D_SHADERS_BLENDER})
source_group("Refactored\\Interfaces" FILES ${REFACTORED_INTERFACES})
source_group("Interfase implementations\\StatsRender" FILES ${INTERFASE_IMPLEMENTATIONS_STATSRENDER})
source_group("Interfase implementations\\RenderFactory" FILES ${INTERFASE_IMPLEMENTATIONS_RENDERFACTORY})
source_group("Interfase implementations\\Debug" FILES ${INTERFASE_IMPLEMENTATIONS_DEBUG})
source_group("Visibility\\HOM Occlusion" FILES ${VISIBILITY_HOM_OCCLUSION})
source_group("Interfase implementations\\EnvironmentRender" FILES ${INTERFASE_IMPLEMENTATIONS_ENVIRONMENTRENDER})
source_group("Models" FILES ${MODELS})
source_group("Interfase implementations\\LensFlare" FILES ${INTERFASE_IMPLEMENTATIONS_LENSFLARE})
source_group("Refactored\\Backend" FILES ${REFACTORED_BACKEND})
source_group("Wallmarks" FILES ${WALLMARKS})
source_group("Interfase implementations\\UI\\UIShader" FILES ${INTERFASE_IMPLEMENTATIONS_UI_UISHADER})
source_group("Visibility\\Sector/Portal" FILES ${VISIBILITY_SECTOR_PORTAL})
source_group("Interfase implementations\\UI\\UISequenceVideoItem" FILES ${INTERFASE_IMPLEMENTATIONS_UI_UISEQUENCEVIDEOITEM})
source_group("Interfase implementations\\ThunderboltRender" FILES ${INTERFASE_IMPLEMENTATIONS_THUNDERBOLTRENDER})
source_group("Interfase implementations\\ApplicationRender" FILES ${INTERFASE_IMPLEMENTATIONS_APPLICATIONRENDER})
source_group("Refactored\\stats_manager" FILES ${REFACTORED_STATS_MANAGER})
source_group("Refactored\\HW" FILES ${REFACTORED_HW})
source_group("Refactored\\Execution &amp; 3D\\Shaders\\Resources\\dx9_R_shader" FILES ${REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES_DX9_R_SHADER})
source_group("Refactored\\Execution &amp; 3D\\Visuals\\Skeleton" FILES ${REFACTORED_EXECUTION__AND__3D_VISUALS_SKELETON})
source_group("Interfase implementations\\FontRender" FILES ${INTERFASE_IMPLEMENTATIONS_FONTRENDER})
source_group("Shading templates\\R1" FILES ${SHADING_TEMPLATES_R1})
source_group("Refactored\\Execution &amp; 3D\\DebugDraw" FILES ${REFACTORED_EXECUTION__AND__3D_DEBUGDRAW})
source_group("Refactored\\Execution &amp; 3D\\Visuals" FILES ${REFACTORED_EXECUTION__AND__3D_VISUALS})
source_group("" FILES ${ROOT_SPECIAL_CONV})
source_group("Stripifier" FILES ${STRIPIFIER})
source_group("Interfase implementations\\FactoryPtr" FILES ${INTERFASE_IMPLEMENTATIONS_FACTORYPTR})
source_group("Refactored\\Execution &amp; 3D\\Shaders\\ShaderManager" FILES ${REFACTORED_EXECUTION__AND__3D_SHADERS_SHADERMANAGER})
source_group("Core" FILES ${CORE})
source_group("Refactored\\Execution &amp; 3D\\Shaders\\Resources" FILES ${REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES})
source_group("Interfase implementations\\ObjectSpaceRender" FILES ${INTERFASE_IMPLEMENTATIONS_OBJECTSPACERENDER})
source_group("Interfase implementations\\RainRender" FILES ${INTERFASE_IMPLEMENTATIONS_RAINRENDER})
source_group("Interfase implementations\\UI\\UIRender" FILES ${INTERFASE_IMPLEMENTATIONS_UI_UIRENDER})
source_group("Interfase implementations\\Debug\\DebugRender" FILES ${INTERFASE_IMPLEMENTATIONS_DEBUG_DEBUGRENDER})
source_group("Shading templates" FILES ${SHADING_TEMPLATES})
source_group("Refactored\\Execution &amp; 3D\\Gamma" FILES ${REFACTORED_EXECUTION__AND__3D_GAMMA})

include_directories(${DXSDK_INCLUDE_DIR})
link_directories(${DXSDK_LIB_DIR})
add_definitions(-DATIMGPUD_DLL -DXRRENDER_R2_EXPORTS -D_SECURE_SCL=0)

# TODO: change precise to fast after msvc bug fix
add_compile_options(/fp:precise /GR "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrRender_R2 SHARED ${ROOT_SPECIAL_CONV}
                               ${INTERFASE_IMPLEMENTATIONS_UI_UISHADER}
                               ${INTERFASE_IMPLEMENTATIONS_UI_UIRENDER}
                               ${INTERFASE_IMPLEMENTATIONS_FACTORYPTR}
                               ${REFACTORED_INTERFACES}
                               ${INTERFASE_IMPLEMENTATIONS_THUNDERBOLTRENDER}
                               ${LIGHTS}
                               ${REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES}
                               ${INTERFASE_IMPLEMENTATIONS_DEBUG}
                               ${REFACTORED_EXECUTION__AND__3D_VISUALS_SKELETON}
                               ${DETAILS}
                               ${REFACTORED_STATS_MANAGER}
                               ${WALLMARKS}
                               ${INTERFASE_IMPLEMENTATIONS_THUNDERBOLTDESCRENDER}
                               ${INTERFASE_IMPLEMENTATIONS_WALLMARKARRAY}
                               ${INTERFASE_IMPLEMENTATIONS_FONTRENDER}
                               ${REFACTORED_EXECUTION__AND__3D_SHADERS_BLENDER}
                               ${INTERFASE_IMPLEMENTATIONS_STATGRAPHRENDER}
                               ${KERNEL}
                               ${VISIBILITY_SECTOR_PORTAL}
                               ${INTERFASE_IMPLEMENTATIONS_RENDERDEVICERENDER}
                               ${CORE}
                               ${REFACTORED_EXECUTION__AND__3D_GAMMA}
                               ${CORE_TARGET_COLORMAP}
                               ${INTERFASE_IMPLEMENTATIONS_ENVIRONMENTRENDER}
                               ${INTERFASE_IMPLEMENTATIONS_RAINRENDER}
                               ${VISIBILITY_HOM_OCCLUSION}
                               ${INTERFASE_IMPLEMENTATIONS_RENDERFACTORY}
                               ${INTERFASE_IMPLEMENTATIONS_STATSRENDER}
                               ${INTERFASE_IMPLEMENTATIONS_OBJECTSPACERENDER}
                               ${SHADING_TEMPLATES}
                               ${REFACTORED_BACKEND}
                               ${STRIPIFIER}
                               ${INTERFASE_IMPLEMENTATIONS_APPLICATIONRENDER}
                               ${INTERFASE_IMPLEMENTATIONS_LENSFLARE}
                               ${SHADING_TEMPLATES_R1}
                               ${MODELS_VISUALS}
                               ${REFACTORED_EXECUTION__AND__3D_DEBUGDRAW}
                               ${INTERFASE_IMPLEMENTATIONS_DEBUG_DEBUGRENDER}
                               ${MODELS}
                               ${CORE_TARGET}
                               ${INTERFASE_IMPLEMENTATIONS_CONSOLERENDER}
                               ${INTERFASE_IMPLEMENTATIONS_UI_UISEQUENCEVIDEOITEM}
                               ${REFACTORED_EXECUTION__AND__3D_SHADERS_RESOURCES_DX9_R_SHADER}
                               ${REFACTORED_EXECUTION__AND__3D_SHADERS_SHADERMANAGER}
                               ${REFACTORED_EXECUTION__AND__3D_VISUALS}
                               ${REFACTORED_HW})
target_link_libraries(xrRender_R2 nvapi d3dx9 xrEngine xrCPU_Pipe xrParticles)