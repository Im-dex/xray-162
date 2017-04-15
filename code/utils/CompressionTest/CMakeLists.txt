cmake_minimum_required(VERSION 3.8)

project(CompressionTest)

set(PPMD ../../engine/xrCore/Coder.hpp
         ../../engine/xrCore/compression_ppmd_stream.h
         ../../engine/xrCore/compression_ppmd_stream_inline.h
         ../../engine/xrCore/PPMd.h
         ../../engine/xrCore/PPMdType.h
         ../../engine/xrCore/SubAlloc.hpp
         ../../engine/xrCore/Model.cpp)

set(ROOT_SPECIAL_CONV CompressionTest.cpp)

set(LZO ../xrCompress/lzo/compr1b.h
        ../xrCompress/lzo/compr1c.h
        ../xrCompress/lzo/config1.h
        ../xrCompress/lzo/config1a.h
        ../xrCompress/lzo/config1b.h
        ../xrCompress/lzo/config1c.h
        ../xrCompress/lzo/config1f.h
        ../xrCompress/lzo/config1x.h
        ../xrCompress/lzo/config1y.h
        ../xrCompress/lzo/config1z.h
        ../xrCompress/lzo/config2a.h
        ../xrCompress/lzo/fake16.h
        ../xrCompress/lzo/lzo1.h
        ../xrCompress/lzo/lzo16bit.h
        ../xrCompress/lzo/lzo1a.h
        ../xrCompress/lzo/lzo1a_de.h
        ../xrCompress/lzo/lzo1b.h
        ../xrCompress/lzo/lzo1b_cc.h
        ../xrCompress/lzo/lzo1b_de.h
        ../xrCompress/lzo/lzo1c.h
        ../xrCompress/lzo/lzo1c_cc.h
        ../xrCompress/lzo/lzo1f.h
        ../xrCompress/lzo/lzo1x.h
        ../xrCompress/lzo/lzo1y.h
        ../xrCompress/lzo/lzo1z.h
        ../xrCompress/lzo/lzo2a.h
        ../xrCompress/lzo/lzo_conf.h
        ../xrCompress/lzo/lzo_dict.h
        ../xrCompress/lzo/lzo_ptr.h
        ../xrCompress/lzo/lzo_util.h
        ../xrCompress/lzo/lzoconf.h
        ../xrCompress/lzo/lzoutil.h
        ../xrCompress/lzo/stats1a.h
        ../xrCompress/lzo/stats1b.h
        ../xrCompress/lzo/stats1c.h
        ../xrCompress/lzo/alloc.c
        ../xrCompress/lzo/io.c
        ../xrCompress/lzo/lzo1.c
        ../xrCompress/lzo/lzo1_99.c
        ../xrCompress/lzo/lzo1a.c
        ../xrCompress/lzo/lzo1a_99.c
        ../xrCompress/lzo/lzo1b_1.c
        ../xrCompress/lzo/lzo1b_2.c
        ../xrCompress/lzo/lzo1b_3.c
        ../xrCompress/lzo/lzo1b_4.c
        ../xrCompress/lzo/lzo1b_5.c
        ../xrCompress/lzo/lzo1b_6.c
        ../xrCompress/lzo/lzo1b_7.c
        ../xrCompress/lzo/lzo1b_8.c
        ../xrCompress/lzo/lzo1b_9.c
        ../xrCompress/lzo/lzo1b_99.c
        ../xrCompress/lzo/lzo1b_9x.c
        ../xrCompress/lzo/lzo1b_cc.c
        ../xrCompress/lzo/lzo1b_d1.c
        ../xrCompress/lzo/lzo1b_d2.c
        ../xrCompress/lzo/lzo1b_rr.c
        ../xrCompress/lzo/lzo1b_xx.c
        ../xrCompress/lzo/lzo1c_1.c
        ../xrCompress/lzo/lzo1c_2.c
        ../xrCompress/lzo/lzo1c_3.c
        ../xrCompress/lzo/lzo1c_4.c
        ../xrCompress/lzo/lzo1c_5.c
        ../xrCompress/lzo/lzo1c_6.c
        ../xrCompress/lzo/lzo1c_7.c
        ../xrCompress/lzo/lzo1c_8.c
        ../xrCompress/lzo/lzo1c_9.c
        ../xrCompress/lzo/lzo1c_99.c
        ../xrCompress/lzo/lzo1c_9x.c
        ../xrCompress/lzo/lzo1c_cc.c
        ../xrCompress/lzo/lzo1c_d1.c
        ../xrCompress/lzo/lzo1c_d2.c
        ../xrCompress/lzo/lzo1c_rr.c
        ../xrCompress/lzo/lzo1c_xx.c
        ../xrCompress/lzo/lzo1f_1.c
        ../xrCompress/lzo/lzo1f_9x.c
        ../xrCompress/lzo/lzo1f_d1.c
        ../xrCompress/lzo/lzo1f_d2.c
        ../xrCompress/lzo/lzo1x_1.c
        ../xrCompress/lzo/lzo1x_1k.c
        ../xrCompress/lzo/lzo1x_1l.c
        ../xrCompress/lzo/lzo1x_1o.c
        ../xrCompress/lzo/lzo1x_9x.c
        ../xrCompress/lzo/lzo1x_d1.c
        ../xrCompress/lzo/lzo1x_d2.c
        ../xrCompress/lzo/lzo1x_d3.c
        ../xrCompress/lzo/lzo1x_o.c
        ../xrCompress/lzo/lzo1y_1.c
        ../xrCompress/lzo/lzo1y_9x.c
        ../xrCompress/lzo/lzo1y_d1.c
        ../xrCompress/lzo/lzo1y_d2.c
        ../xrCompress/lzo/lzo1y_d3.c
        ../xrCompress/lzo/lzo1y_o.c
        ../xrCompress/lzo/lzo1z_9x.c
        ../xrCompress/lzo/lzo1z_d1.c
        ../xrCompress/lzo/lzo1z_d2.c
        ../xrCompress/lzo/lzo1z_d3.c
        ../xrCompress/lzo/lzo2a_9x.c
        ../xrCompress/lzo/lzo2a_d1.c
        ../xrCompress/lzo/lzo2a_d2.c
        ../xrCompress/lzo/lzo_crc.c
        ../xrCompress/lzo/lzo_dll.c
        ../xrCompress/lzo/lzo_init.c
        ../xrCompress/lzo/lzo_ptr.c
        ../xrCompress/lzo/lzo_str.c
        ../xrCompress/lzo/lzo_util.c)

source_group("PPMd" FILES ${PPMD})
source_group("" FILES ${ROOT_SPECIAL_CONV})
source_group("LZO" FILES ${LZO})

add_definitions(-D_CONSOLE)

add_executable(CompressionTest ${PPMD}
                               ${ROOT_SPECIAL_CONV}
                               ${LZO})
set_target_properties(CompressionTest PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")