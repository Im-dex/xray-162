//----------------------------------------------------
// file: FileSystem.h
//----------------------------------------------------
#pragma once

class XRCORE_API EFS_Utils final {
    EFS_Utils() = delete;
public:
    static xr_string ChangeFileExt(const std::string_view& src, const char* ext);
};
