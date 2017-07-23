#pragma once

#include "lzhuf.h"
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <share.h>

void* FileDownload(const char* fn, size_t* pdwSize = nullptr);
void FileCompress(const char* fn, const char* sign, void* data, const size_t size);
void* FileDecompress(const char* fn, const char* sign, size_t* size = nullptr);

class CFileWriter : public IWriter {
    FILE* hf;
public:
    CFileWriter(const char* name, const bool exclusive) {
        R_ASSERT(name && name[0]);
        fName = name;
        createPath(*fName);
        if (exclusive) {
            int handle = _sopen(*fName, _O_WRONLY | _O_TRUNC | _O_CREAT | _O_BINARY, SH_DENYWR);
            hf = _fdopen(handle, "wb");
        } else {
            hf = fopen(*fName, "wb");
            if (!hf)
                Msg("!Can't write file: '%s'. Error: '%s'.", *fName, _sys_errlist[errno]);
        }
    }

    virtual ~CFileWriter() {
        if (hf) {
            fclose(hf);
            // release RO attrib
            auto dwAttr = GetFileAttributes(*fName);
            if ((dwAttr != DWORD(-1)) && (dwAttr & FILE_ATTRIBUTE_READONLY)) {
                dwAttr &= ~FILE_ATTRIBUTE_READONLY;
                SetFileAttributes(*fName, dwAttr);
            }
        }
    }
    // kernel
    void w(const void* _ptr, const size_t count) override {
        if (hf && (0 != count)) {
            const size_t mb_sz = 0x1000000;
            const auto* ptr = static_cast<const u8*>(_ptr);
            size_t req_size = 0;
            for (req_size = count; req_size > mb_sz; req_size -= mb_sz, ptr += mb_sz) {
                const auto W = fwrite(ptr, mb_sz, 1, hf);
                R_ASSERT3(W == 1, "Can't write mem block to file. Disk maybe full.",
                          _sys_errlist[errno]);
            }

            if (req_size > 0) {
                const auto W = fwrite(ptr, req_size, 1, hf);
                R_ASSERT3(W == 1, "Can't write mem block to file. Disk maybe full.",
                          _sys_errlist[errno]);
            }
        }
    }

    void seek(const size_t pos) override {
        if (hf)
            fseek(hf, pos, SEEK_SET);
    }

    size_t tell() override { return hf ? ftell(hf) : 0; }
    bool valid() override { return hf; }

    void flush() override {
        if (hf)
            fflush(hf);
    }
};

// It automatically frees memory after destruction
class CTempReader : public IReader {
public:
    CTempReader(void* data, const int size, const int iterpos) : IReader(data, size, iterpos) {}
    virtual ~CTempReader();
};

class CPackReader : public IReader {
    void* base_address;
public:
    CPackReader(void* base, void* data, const int size) : IReader(data, size) {
        base_address = base;
    }
    virtual ~CPackReader();
};

class XRCORE_API CFileReader : public IReader {
public:
    CFileReader(const char* name);
    virtual ~CFileReader();
};

class CCompressedReader : public IReader {
public:
    CCompressedReader(const char* name, const char* sign);
    virtual ~CCompressedReader();
};

class CVirtualFileReader : public IReader {
    void *hSrcFile, *hSrcMap;
public:
    CVirtualFileReader(const char* cFileName);
    virtual ~CVirtualFileReader();
};
