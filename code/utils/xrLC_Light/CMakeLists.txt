cmake_minimum_required(VERSION 3.8)

project(xrLC_Light)

set(LIGHT_LIGHTS base_lighting.h
                 light_point.h
                 R_light.h
                 base_lighting.cpp)

set(LIGHT_NET_NEW_NET_USER_GL_DATA detail_net_global_data.h
                                   gl_base_cl_data.h
                                   implicit_net_global_data.h
                                   lc_net_global_data.h
                                   lm_net_global_data.h
                                   net_all_globals.h
                                   net_global_data.h
                                   ref_model_net_global_data.h
                                   detail_net_global_data.cpp
                                   gl_base_cl_data.cpp
                                   implicit_net_global_data.cpp
                                   lc_net_global_data.cpp
                                   lm_net_global_data.cpp
                                   net_global_data.cpp
                                   ref_model_net_global_data.cpp)

set(LIGHT_NET_NEW_TASK_MANAGER lcnet_task_manager.h
                               net_exec_pool.h
                               lcnet_task_manager.cpp
                               lcnet_task_menager_run_task.cpp
                               net_exec_pool.cpp)

set(DO_LIGHT detail_slot_calculate.h
             DetailFormat.h
             global_calculation_data.h
             global_slots_data.h
             LightThread.h
             recalculation.h
             xrLightDoNet.h
             compiler.cpp
             detail_slot_calculate.cpp
             global_calculation_data.cpp
             global_slots_data.cpp
             LightThread.cpp
             recalculation.cpp
             xrLightDoNet.cpp
             ../../engine/xrEngine/xrLoadSurface.cpp)

set(LIGHT_LIGHTVERTEX xrLightVertex.h
                      xrLightVertex.cpp
                      xrLightVertexNet.cpp)

set(KERNEL _d3d_extensions.h
           stdafx.h
           xrLC_Light.h
           xrThread.h
           stdafx.cpp
           xrLC_Light.cpp
           xrThread.cpp)

set(LIGHT_MODELS fitter.h
                 mu_model_face.h
                 mu_model_face_defs.h
                 xrMU_Model.h
                 xrMU_Model_Reference.h
                 fitter.cpp
                 mu_model_face.cpp
                 xrMU_Model.cpp
                 xrMU_Model_Calc_faceopacity.cpp
                 xrMU_Model_Calc_materials.cpp
                 xrMU_Model_Calc_normals.cpp
                 xrMU_Model_export_cform_rcast.cpp
                 xrMU_Model_Load.cpp
                 xrMU_Model_Reference.cpp)

set(LIGHT_XRDEFLECTOR execute_statistics.h
                      uv_tri.h
                      xrDeflector.h
                      xrDeflectorDefs.h
                      xrImage_Resampler.h
                      xrIsect.h
                      execute_statistics.cpp
                      uv_tri.cpp
                      xrDeflectoL_Direct.cpp
                      xrDeflector.cpp
                      xrDeflectorLight.cpp
                      xrImage_Resampler.cpp)

set(LIGHT_MESH base_basis.h
               base_face.h
               calculate_normals.h
               itterate_adjacents_static.h
               MeshStructure.h
               xrFace.h
               xrFaceDefs.h
               base_basis.cpp
               base_face.cpp
               xrFace.cpp)

set(LIGHT_LIGHTIMPLICIT xrLight_Implicit.h
                        xrLight_ImplicitCalcGlobs.h
                        xrLight_ImplicitDeflector.h
                        xrLight_ImplicitRun.h
                        xrLight_ImlicitNet.cpp
                        xrLight_Implicit.cpp
                        xrLight_ImplicitCalcGlobs.cpp
                        xrLight_ImplicitDeflector.cpp
                        xrLight_ImplicitThread.cpp)

set(LIGHT_XRLC_GLOBALDATA vector_clear.h
                          xrLC_GlobalData.h
                          MeshStaic.cpp
                          xrLC_GlobalData.cpp)

set(LIGHT_COLOR base_color.h
                base_color.cpp)

set(LIGHT_LIGHTMAPS Lightmap.h
                    lm_layer.h
                    xrImage_Filter.h
                    Lightmap.cpp
                    lm_layer.cpp
                    xrImage_Filter.cpp)

set(LIGHT_NET_DEPR net_light.h
                   net_light_task.h
                   net_task.h
                   net_task_manager.h
                   net_light_task.cpp)

set(LIGHT_NET_NEW lightstab_interface.h
                  net_cl_data_prepare.h
                  net_execution_factory.h
                  net_execution_globals.h
                  net_global_data_cleanup.h
                  net_task_callback.h
                  net_cl_data_prepare.cpp
                  net_execution_factory.cpp
                  net_execution_factory_register.cpp
                  net_execution_globals.cpp
                  net_global_data_cleanup.cpp
                  net_task_callback.cpp)

set(LIGHT_TEXTURES b_build_texture.h
                   ETextureParams.h
                   tcf.h
                   tga.h
                   b_build_texture.cpp
                   ETextureParams.cpp
                   tcf.cpp
                   tga.cpp)

set(LIGHT_NET file_compress.h
              light_execute.h
              net_stream.h
              file_compress.cpp
              ../hxgrid/Interface/hxGridInterface.cpp
              light_execute.cpp
              net_stream.cpp)

set(LIGHT_NET_NEW_NET_USER_EXECUTION lcnet_execution_tasks_add.h
                                     net_all_executions.h
                                     net_execution.h
                                     net_execution_detail_light.h
                                     net_execution_implicit_light.h
                                     net_execution_lightmaps.h
                                     net_execution_mu_base.h
                                     net_execution_mu_ref.h
                                     net_execution_vertex_light.h
                                     net_execution.cpp
                                     net_execution_detail_light.cpp
                                     net_execution_implicit_light.cpp
                                     net_execution_lightmaps.cpp
                                     net_execution_mu_base.cpp
                                     net_execution_mu_ref.cpp
                                     net_execution_vertex_light.cpp
                                     net_lightmaps_add_task.cpp)

set(ROOT_SPECIAL_CONV ../Shader_xrLC.h
                      ReadMe.txt)

set(LIGHT_MODELS_MU_LIGHT mu_light_net.h
                          mu_model_light.h
                          mu_model_light_threads.h
                          mu_light_net.cpp
                          mu_model_light.cpp
                          mu_model_light_threads.cpp
                          xrMU_Model_Calc_lighting.cpp
                          xrMU_Model_Reference_Calc_Lighting.cpp)

set(LIGHT hash2D.h)

set(LIGHT_SERIALIZE serialize.h
                    serialize.cpp)

source_group("Light\\Lights" FILES ${LIGHT_LIGHTS})
source_group("Light\\Net\\new\\net_user_gl_data" FILES ${LIGHT_NET_NEW_NET_USER_GL_DATA})
source_group("Light\\Net\\new\\task_manager" FILES ${LIGHT_NET_NEW_TASK_MANAGER})
source_group("do_light" FILES ${DO_LIGHT})
source_group("Light\\LightVertex" FILES ${LIGHT_LIGHTVERTEX})
source_group("kernel" FILES ${KERNEL})
source_group("Light\\models" FILES ${LIGHT_MODELS})
source_group("Light\\xrDeflector" FILES ${LIGHT_XRDEFLECTOR})
source_group("Light\\Mesh" FILES ${LIGHT_MESH})
source_group("Light\\LightImplicit" FILES ${LIGHT_LIGHTIMPLICIT})
source_group("Light\\xrLC_GlobalData" FILES ${LIGHT_XRLC_GLOBALDATA})
source_group("Light\\color" FILES ${LIGHT_COLOR})
source_group("Light\\Lightmaps" FILES ${LIGHT_LIGHTMAPS})
source_group("Light\\Net\\depr" FILES ${LIGHT_NET_DEPR})
source_group("Light\\Net\\new" FILES ${LIGHT_NET_NEW})
source_group("Light\\Textures" FILES ${LIGHT_TEXTURES})
source_group("Light\\Net" FILES ${LIGHT_NET})
source_group("Light\\Net\\new\\net_user_execution" FILES ${LIGHT_NET_NEW_NET_USER_EXECUTION})
source_group("" FILES ${ROOT_SPECIAL_CONV})
source_group("Light\\models\\mu_light" FILES ${LIGHT_MODELS_MU_LIGHT})
source_group("Light" FILES ${LIGHT})
source_group("Light\\serialize" FILES ${LIGHT_SERIALIZE})

include_directories(${DXSDK_INCLUDE_DIR} ../xrQSlim/src)

add_definitions(-DXRLC_LIGHT_EXPORTS)

add_compile_options(/fp:fast "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/../hxgrid/Interface/hxGridInterface.cpp PROPERTIES COMPILE_FLAGS /Y-)

add_library(xrLC_Light SHARED ${ROOT_SPECIAL_CONV}
                              ${LIGHT}
                              ${LIGHT_COLOR}
                              ${LIGHT_XRLC_GLOBALDATA}
                              ${LIGHT_MODELS_MU_LIGHT}
                              ${LIGHT_MESH}
                              ${LIGHT_LIGHTVERTEX}
                              ${LIGHT_NET_NEW_TASK_MANAGER}
                              ${DO_LIGHT}
                              ${LIGHT_TEXTURES}
                              ${LIGHT_NET_NEW_NET_USER_EXECUTION}
                              ${LIGHT_NET_NEW_NET_USER_GL_DATA}
                              ${LIGHT_LIGHTS}
                              ${LIGHT_LIGHTMAPS}
                              ${LIGHT_LIGHTIMPLICIT}
                              ${LIGHT_XRDEFLECTOR}
                              ${KERNEL}
                              ${LIGHT_NET_DEPR}
                              ${LIGHT_NET_NEW}
                              ${LIGHT_SERIALIZE}
                              ${LIGHT_MODELS}
                              ${LIGHT_NET})
set_target_properties(xrLC_Light PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
target_link_libraries(xrLC_Light xrCore xrDXT xrCDB zlib FreeImage)