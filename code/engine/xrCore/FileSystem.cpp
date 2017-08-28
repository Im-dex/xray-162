#include "stdafx.h"

xr_string EFS_Utils::ChangeFileExt(const std::string_view src, const std::string_view ext) {
    // TODO: [imdex] use stdfs::path.replace_extension instead
    xr_string tmp;
    const char* src_ext = strext(src.data());
    if (src_ext) {
        const size_t ext_pos = src_ext - src.data();
        tmp.assign(src, 0, ext_pos);
    } else {
        tmp = src;
    }
    tmp += ext;
    return tmp;
}
