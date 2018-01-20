//----------------------------------------------------
// file: FileSystem.h
//----------------------------------------------------
#pragma once

class XRCORE_API EFS_Utils final {
    EFS_Utils() = delete;
public:
    static std::string ChangeFileExt(const std::string_view src, const std::string_view ext);
};
