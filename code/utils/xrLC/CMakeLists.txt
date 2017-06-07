cmake_minimum_required(VERSION 3.8)

project(xrLC)

set(STARSTARSTAR_COMPILER_STARSTARSTAR_NET net.h
                                           ../hxgrid/Interface/hxGridInterface.cpp
                                           net.cpp)

set(KERNEL defines.h
           StdAfx.h
           StdAfx.cpp
           xrLC.cpp)

set(CDB cl_intersect.h)

set(KERNEL_RES resource.h
               resource.rc)

set(EXTERNAL_NV_MENDER2002_NV_BASIS NvMender2002/nv_algebra.h
                                    NvMender2002/nv_math.h
                                    NvMender2002/nv_mathdecl.h
                                    NvMender2002/nv_algebra.cpp)

set(STARSTARSTAR_COMPILER_STARSTARSTAR_INTERNAL vbm.h)

set(EXTERNAL_NV_MENDER2002 NvMender2002/NVMeshMender.h
                           NvMender2002/NVMeshMender.cpp)

set(KERNEL_LOG cl_log.h
               cl_log.cpp)

set(STARSTARSTAR_COMPILER_STARSTARSTAR_XRAY ArbitraryList.h
                                            OGF_Face.h
                                            PropSlimTools.h
                                            fmesh.cpp
                                            OGF_CalculateTB.cpp
                                            OGF_Face.cpp
                                            OGF_Face_Save.cpp
                                            OGF_Face_Sphere.cpp
                                            OGF_Face_Stripify.cpp
                                            OGF_RemoveIsolatedVerts.cpp)

set(ROOT_SPECIAL_CONV xrGameMaterials.h)

set(EXTERNAL_NV_STRIPS NV_Library/NvTriStrip.h
                       NV_Library/NvTriStripObjects.h
                       NV_Library/VertexCache.h
                       NV_Library/NvTriStrip.cpp
                       NV_Library/NvTriStripObjects.cpp
                       NV_Library/VertexCache.cpp)

set(STARSTARSTAR_COMPILER_STARSTARSTAR _rect.h
                                       Build.h
                                       ELight_def.h
                                       ../common/face_smoth_flags.h
                                       ../common/itterate_adjacents.h
                                       Sector.h
                                       ../Shader_xrLC.h
                                       xrPhase_MergeLM_Rect.h
                                       Build.cpp
                                       Build_Load.cpp
                                       Sector.cpp
                                       xrBuildCForm.cpp
                                       xrBuildRapidModel.cpp
                                       xrCalcNormals.cpp
                                       xrFlex2OGF.cpp
                                       xrLight.cpp
                                       ../../engine/xrEngine/xrLoadSurface.cpp
                                       xrOptimizeCFORM_qslim.cpp
                                       xrPhase_AdaptiveHT.cpp
                                       xrPhase_AdaptiveHT_qslim.cpp
                                       xrPhase_GI.cpp
                                       xrPhase_MergeGeometry.cpp
                                       xrPhase_MergeLM.cpp
                                       xrPhase_MergeLM_Surface.cpp
                                       xrPhase_ResolveMaterials.cpp
                                       xrPhase_Subdivide.cpp
                                       xrPhase_TangentBasis.cpp
                                       xrPhase_UVmap.cpp
                                       xrPreOptimize.cpp
                                       xrSaveLights.cpp
                                       xrSaveOGF.cpp
                                       xrSectors.cpp
                                       xrT_Junction.cpp)

set(STARSTARSTAR_COMPILER_STARSTARSTAR_MODEL xrMU_Model_Calc_ogf.cpp
                                             xrMU_Model_export_geometry.cpp
                                             xrMU_Model_export_OGF.cpp)

set(EXTERNAL b_globals.h
             MeshMenderLayerOGF.h
             MeshMenderLayerOrdinaryStatic.h
             progmesh.h
             std_classes.h
             xrHemisphere.h
             xrOcclusion.h
             xrSpherical.h)

set(EXTERNAL_NV_MENDER2003 ../common/NvMender2003/convert.h
                           ../common/NvMender2003/mender_input_output.h
                           ../common/NvMender2003/NVMeshMender.h
                           ../common/NvMender2003/remove_isolated_verts.h
                           ../common/NvMender2003/NVMeshMender.cpp)

file(GLOB MGC_SRC mgc/*.h mgc/*.cpp)

source_group("*** COMPILER ***\\net" FILES ${STARSTARSTAR_COMPILER_STARSTARSTAR_NET})
source_group("Kernel" FILES ${KERNEL})
source_group("CDB" FILES ${CDB})
source_group("Kernel\\Res" FILES ${KERNEL_RES})
source_group("External\\NV_Mender2002\\NV_Basis" FILES ${EXTERNAL_NV_MENDER2002_NV_BASIS})
source_group("*** COMPILER ***\\Internal" FILES ${STARSTARSTAR_COMPILER_STARSTARSTAR_INTERNAL})
source_group("External\\NV_Mender2002" FILES ${EXTERNAL_NV_MENDER2002})
source_group("Kernel\\Log" FILES ${KERNEL_LOG})
source_group("*** COMPILER ***\\XRAY" FILES ${STARSTARSTAR_COMPILER_STARSTARSTAR_XRAY})
source_group("" FILES ${ROOT_SPECIAL_CONV})
source_group("External\\NV_Strips" FILES ${EXTERNAL_NV_STRIPS})
source_group("*** COMPILER ***" FILES ${STARSTARSTAR_COMPILER_STARSTARSTAR})
source_group("*** COMPILER ***\\Model" FILES ${STARSTARSTAR_COMPILER_STARSTARSTAR_MODEL})
source_group("External" FILES ${EXTERNAL})
source_group("External\\NV_Mender2003" FILES ${EXTERNAL_NV_MENDER2003})
source_group("mgc" FILES ${MGC_SRC})

include_directories(${DXSDK_INCLUDE_DIR} ../xrQSlim/src)
link_directories(${DXSDK_LIB_DIR} ../ETools)

add_definitions(-D_USE_MATH_DEFINES -D_SECURE_SCL=0)

add_compile_options(/fp:fast /GR "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/../hxgrid/Interface/hxGridInterface.cpp PROPERTIES COMPILE_FLAGS /Y-)

add_executable(xrLC ${ROOT_SPECIAL_CONV}
                    ${EXTERNAL_NV_MENDER2002_NV_BASIS}
                    ${STARSTARSTAR_COMPILER_STARSTARSTAR}
                    ${CDB}
                    ${KERNEL_LOG}
                    ${EXTERNAL_NV_MENDER2002}
                    ${STARSTARSTAR_COMPILER_STARSTARSTAR_NET}
                    ${STARSTARSTAR_COMPILER_STARSTARSTAR_XRAY}
                    ${EXTERNAL_NV_MENDER2003}
                    ${EXTERNAL}
                    ${EXTERNAL_NV_STRIPS}
                    ${STARSTARSTAR_COMPILER_STARSTARSTAR_INTERNAL}
                    ${STARSTARSTAR_COMPILER_STARSTARSTAR_MODEL}
                    ${KERNEL_RES}
                    ${KERNEL}
                    ${MGC_SRC})
set_target_properties(xrLC PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
target_link_libraries(xrLC xrDXT ETools xrLC_Light xrQSlim xrCore xrCDB FreeImage comctl32 winmm imagehlp d3dx9 ColorPicker)