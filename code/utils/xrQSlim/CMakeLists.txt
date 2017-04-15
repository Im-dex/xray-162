cmake_minimum_required(VERSION 3.8)

project(xrQSlim)

set(KERNEL src/MxBlock.h
           src/MxBlock2.h
           src/MxDynBlock.h
           src/MxGeoPrims.h
           src/MxHeap.h
           src/stdafx.h
           src/MxHeap.cpp)

set(QSLIM src/MxPropSlim.h
          src/MxQSlim.h
          src/MxStdSlim.h
          src/MxPropSlim.cpp
          src/MxQSlim.cpp
          src/MxStdSlim.cpp)

set(MATH src/geom3d.h
         src/mat2.h
         src/mat3.h
         src/mat4.h
         src/mixmops.h
         src/mixvops.h
         src/MxDefines.h
         src/MxGeom3D.h
         src/MxMat2.h
         src/MxMat3.h
         src/MxMat4.h
         src/MxMatrix.h
         src/MxQMetric.h
         src/MxQMetric3.h
         src/MxVec3.h
         src/MxVec4.h
         src/MxVector.h
         src/vec2.h
         src/vec3.h
         src/vec4.h
         src/mat2.cpp
         src/mat3.cpp
         src/mat4.cpp
         src/mixmops.cpp
         src/MxGeom3D.cpp
         src/MxMat3-jacobi.cpp
         src/MxMat4-jacobi.cpp
         src/MxMatrix.cpp
         src/MxQMetric.cpp
         src/MxQMetric3.cpp)

set(MODEL src/MxBlockModel.h
          src/MxStdModel.h
          src/MxBlockModel.cpp
          src/MxStdModel.cpp)

source_group("Kernel" FILES ${KERNEL})
source_group("QSlim" FILES ${QSLIM})
source_group("Math" FILES ${MATH})
source_group("Model" FILES ${MODEL})

add_compile_options(/fp:fast /GR)
add_definitions(-DXR_QSLIM_EXPORTS -D_SECURE_SCL=0)

add_library(xrQSlim STATIC ${KERNEL}
                           ${QSLIM}
                           ${MATH}
                           ${MODEL})
target_include_directories(xrQSlim PUBLIC src)