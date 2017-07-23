#include "stdafx.h"

#include "fs_internal.h"

#pragma warning(disable : 4995)
#include <io.h>
#include <direct.h>
#include <fcntl.h>
#include <sys\stat.h>
#pragma warning(default : 4995)

#ifdef FS_DEBUG
XRCORE_API u32 g_file_mapped_memory = 0;
u32 g_file_mapped_count = 0;
typedef xr_map<u32, std::pair<u32, shared_str>> FILE_MAPPINGS;
FILE_MAPPINGS g_file_mappings;

void register_file_mapping(void* address, const u32& size, LPCSTR file_name) {
    FILE_MAPPINGS::const_iterator I = g_file_mappings.find(*(u32*)&address);
    VERIFY(I == g_file_mappings.end());
    g_file_mappings.insert(
        std::make_pair(*(u32*)&address, std::make_pair(size, shared_str(file_name))));

    //	Msg								("++register_file_mapping(%2d):   [0x%08x]%s", g_file_mapped_count + 1,
    //*((u32*)&address), file_name);

    g_file_mapped_memory += size;
    ++g_file_mapped_count;
#ifdef USE_MEMORY_MONITOR
    //	memory_monitor::monitor_alloc	(addres,size,"file mapping");
    string512 temp;
    xr_sprintf(temp, sizeof(temp), "file mapping: %s", file_name);
    memory_monitor::monitor_alloc(address, size, temp);
#endif // USE_MEMORY_MONITOR
}

void unregister_file_mapping(void* address, const u32& size) {
    FILE_MAPPINGS::iterator I = g_file_mappings.find(*(u32*)&address);
    VERIFY(I != g_file_mappings.end());
    //	VERIFY2							((*I).second.first == size,make_string("file mapping sizes are
    //different: %d -> %d",(*I).second.first,size));
    g_file_mapped_memory -= (*I).second.first;
    --g_file_mapped_count;

    //	Msg								("--unregister_file_mapping(%2d): [0x%08x]%s", g_file_mapped_count + 1,
    //*((u32*)&address), (*I).second.second.c_str());

    g_file_mappings.erase(I);

#ifdef USE_MEMORY_MONITOR
    memory_monitor::monitor_free(address);
#endif // USE_MEMORY_MONITOR
}

XRCORE_API void dump_file_mappings() {
    Msg("* active file mappings (%d):", g_file_mappings.size());

    FILE_MAPPINGS::const_iterator I = g_file_mappings.begin();
    FILE_MAPPINGS::const_iterator E = g_file_mappings.end();
    for (; I != E; ++I)
        Msg("* [0x%08x][%d][%s]", (*I).first, (*I).second.first, (*I).second.second.c_str());
}
#endif // DEBUG
//////////////////////////////////////////////////////////////////////
// Tools
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------
void createPath(const stdfs::path& path) {
    std::error_code e;
    stdfs::create_directories(path, e);
    (void)e;
}

static errno_t open_internal(const char* fn, int& handle) {
    return _sopen_s(&handle, fn, _O_RDONLY | _O_BINARY, _SH_DENYNO, _S_IREAD);
}

bool file_handle_internal(const char* file_name, size_t& size, int& file_handle) {
    if (open_internal(file_name, file_handle)) {
        /*Sleep(1);
        if (open_internal(file_name, file_handle))*/
            return false;
    }

    size = _filelength(file_handle);
    return true;
}

void* FileDownload(const char* file_name, const int& file_handle, size_t& file_size) {
    void* buffer = Memory.mem_alloc(file_size
#ifdef DEBUG_MEMORY_NAME
                                    ,
                                    "FILE in memory"
#endif // DEBUG_MEMORY_NAME
    );

    const auto r_bytes = _read(file_handle, buffer, file_size);
    R_ASSERT3(file_size == static_cast<size_t>(r_bytes), "can't read from file : ", file_name);

    R_ASSERT3(!_close(file_handle), "can't close file : ", file_name);
    return buffer;
}

void* FileDownload(const char* file_name, size_t* buffer_size) {
    int file_handle;
    R_ASSERT3(file_handle_internal(file_name, *buffer_size, file_handle),
              "can't open file : ", file_name);

    return FileDownload(file_name, file_handle, *buffer_size);
}

using MARK = std::array<char, 9>;

inline void mk_mark(MARK& M, const char* S) {
    strncpy_s(M.data(), sizeof(M), S, 8);
}

void FileCompress(const char* fn, const char* sign, void* data, const size_t size) {
    MARK M;
    mk_mark(M, sign);

    const auto H = _open(fn, O_BINARY | O_CREAT | O_WRONLY | O_TRUNC, S_IREAD | S_IWRITE);
    R_ASSERT2(H > 0, fn);
    _write(H, &M, 8);
    _writeLZ(H, data, size);
    _close(H);
}

void* FileDecompress(const char* fn, const char* sign, size_t* size) {
    MARK M, F;
    mk_mark(M, sign);

    const auto H = _open(fn, O_BINARY | O_RDONLY);
    R_ASSERT2(H > 0, fn);
    _read(H, &F, 8);
    if (strncmp(M.data(), F.data(), 8) != 0) {
        F[8] = 0;
        Msg("FATAL: signatures doesn't match, file(%s) / requested(%s)", F, sign);
    }
    R_ASSERT(strncmp(M.data(), F.data(), 8) == 0);

    void* ptr = nullptr;
    const size_t SZ = _readLZ(H, ptr, _filelength(H) - 8);
    _close(H);
    if (size)
        *size = SZ;
    return ptr;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------
// memory
CMemoryWriter::~CMemoryWriter() { xr_free(data); }

void CMemoryWriter::w(const void* ptr, const size_t count) {
    if (position + count > mem_size) {
        // reallocate
        if (mem_size == 0)
            mem_size = 128;
        while (mem_size <= (position + count))
            mem_size *= 2;
        if (!data)
            data = static_cast<u8*>(Memory.mem_alloc(mem_size
#ifdef DEBUG_MEMORY_NAME
                                           ,
                                           "CMemoryWriter - storage"
#endif // DEBUG_MEMORY_NAME
            ));
        else
            data = static_cast<u8*>(Memory.mem_realloc(data, mem_size
#ifdef DEBUG_MEMORY_NAME
                                             ,
                                             "CMemoryWriter - storage"
#endif // DEBUG_MEMORY_NAME
            ));
    }
    std::memcpy(data + position, ptr, count);
    position += count;
    if (position > file_size)
        file_size = position;
}

// static const u32 mb_sz = 0x1000000;
bool CMemoryWriter::save_to(const char* fn) {
    IWriter* F = FS.w_open(fn);
    if (F) {
        F->w(pointer(), size());
        FS.w_close(F);
        return true;
    }
    return false;
}

void IWriter::open_chunk(const u32 type) {
    w_u32(type);
    chunk_pos.push(tell());
    w_u32(0); // the place for 'size'
}

void IWriter::close_chunk() {
    VERIFY(!chunk_pos.empty());

    const auto pos = tell();
    seek(chunk_pos.top());
    w_u32(pos - chunk_pos.top() - 4);
    seek(pos);
    chunk_pos.pop();
}

// returns size of currently opened chunk, 0 otherwise
size_t IWriter::chunk_size() {
    if (chunk_pos.empty())
        return 0;
    return tell() - chunk_pos.top() - 4;
}

void IWriter::w_compressed(void* ptr, const size_t count) {
    u8* dest = nullptr;
    unsigned dest_sz = 0;
    _compressLZ(&dest, &dest_sz, ptr, count);

    if (dest && dest_sz)
        w(dest, dest_sz);
    xr_free(dest);
}

void IWriter::w_chunk(const u32 type, void* data, const size_t size) {
    open_chunk(type);
    if (type & CFS_CompressMark)
        w_compressed(data, size);
    else
        w(data, size);
    close_chunk();
}

void IWriter::w_sdir(const Fvector& D) {
    Fvector C;
    float mag = D.magnitude();
    if (mag > EPS_S) {
        C.div(D, mag);
    } else {
        C.set(0, 0, 1);
        mag = 0;
    }
    w_dir(C);
    w_float(mag);
}

//---------------------------------------------------
// base stream
IReader* IReader::open_chunk(const u32 ID) {
    bool bCompressed;

    const auto dwSize = find_chunk(ID, &bCompressed);
    if (dwSize != 0) {
        if (bCompressed) {
            u8* dest;
            unsigned dest_sz;
            _decompressLZ(&dest, &dest_sz, pointer(), dwSize);
            return xr_new<CTempReader>(dest, dest_sz, tell() + dwSize);
        } else {
            return xr_new<IReader>(pointer(), dwSize, tell() + dwSize);
        }
    } else
        return nullptr;
}

// TODO: imdex note: pay attention!
void IReader::close() { xr_delete((IReader*)this); }

IReader* IReader::open_chunk_iterator(u32& ID, IReader* _prev) {
    if (!_prev) {
        // first
        rewind();
    } else {
        // next
        seek(_prev->iterpos);
        _prev->close();
    }

    //	open
    if (elapsed() < 8)
        return nullptr;

    ID = r_u32();
    const size_t _size = r_u32();
    if (ID & CFS_CompressMark) {
        // compressed
        u8* dest;
        unsigned dest_sz;
        _decompressLZ(&dest, &dest_sz, pointer(), _size);
        return xr_new<CTempReader>(dest, dest_sz, tell() + _size);
    } else {
        // normal
        return xr_new<IReader>(pointer(), _size, tell() + _size);
    }
}

void IReader::r(void* p, const size_t cnt) {
    VERIFY(Pos + cnt <= Size);
    std::memcpy(p, pointer(), cnt);
    advance(cnt);
#ifdef DEBUG
    if (dynamic_cast<CFileReader*>(this) || dynamic_cast<CVirtualFileReader*>(this)) {
        FS.dwOpenCounter++;
    }
#endif
};

inline bool is_term(const char a) { return (a == 13) || (a == 10); }

size_t IReader::advance_term_string() {
    size_t sz = 0;
    while (!eof()) {
        Pos++;
        sz++;
        if (!eof() && is_term(data[Pos])) {
            while (!eof() && is_term(data[Pos]))
                Pos++;
            break;
        }
    }
    return sz;
}

void IReader::r_string(char* dest, const size_t tgt_sz) {
    char* src = data + Pos;
    const auto sz = advance_term_string();
    R_ASSERT2(sz < (tgt_sz - 1), "Dest string less than needed.");
    R_ASSERT(!IsBadReadPtr(src, sz));

    strncpy_s(dest, tgt_sz, src, sz);
    dest[sz] = 0;
}

void IReader::r_string(xr_string& dest) {
    const char* src = data + Pos;
    const auto sz = advance_term_string();
    dest.assign(src, sz);
}

void IReader::r_stringZ(char* dest, const size_t tgt_sz) {
    const auto sz = std::strlen(data);
    R_ASSERT2(sz < tgt_sz, "Dest string less than needed.");
    while ((data[Pos] != 0) && !eof())
        *dest++ = data[Pos++];
    *dest = 0;
    Pos++;
}

void IReader::r_stringZ(shared_str& dest) {
    dest = data + Pos;
    Pos += dest.size() + 1;
}

void IReader::r_stringZ(xr_string& dest) {
    dest = data + Pos;
    Pos += int(dest.size() + 1);
}

void IReader::skip_stringZ() {
    char* src = data;
    while ((src[Pos] != 0) && !eof())
        Pos++;
    Pos++;
}

//---------------------------------------------------
// temp stream
CTempReader::~CTempReader() { xr_free(data); };
//---------------------------------------------------
// pack stream
CPackReader::~CPackReader() {
#ifdef FS_DEBUG
    unregister_file_mapping(base_address, Size);
#endif // DEBUG

    UnmapViewOfFile(base_address);
};
//---------------------------------------------------
// file stream
CFileReader::CFileReader(const char* name) {
    // TODO: pay attention!
    size_t sz = Size;
    data = static_cast<char*>(FileDownload(name, &sz));
    Size = sz;
    Pos = 0;
};
CFileReader::~CFileReader() { xr_free(data); };
//---------------------------------------------------
// compressed stream
CCompressedReader::CCompressedReader(const char* name, const char* sign) {
    size_t sz = Size;
    data = static_cast<char*>(FileDecompress(name, sign, &sz));
    Size = sz;
    Pos = 0;
}
CCompressedReader::~CCompressedReader() { xr_free(data); };

CVirtualFileRW::CVirtualFileRW(const char* cFileName) {
    // Open the file
    hSrcFile = CreateFile(cFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, nullptr,
                          OPEN_EXISTING, 0, nullptr);
    R_ASSERT3(hSrcFile != INVALID_HANDLE_VALUE, cFileName, Debug.error2string(GetLastError()));
    Size = static_cast<int>(GetFileSize(hSrcFile, nullptr));
    R_ASSERT3(Size, cFileName, Debug.error2string(GetLastError()));

    hSrcMap = CreateFileMapping(hSrcFile, nullptr, PAGE_READWRITE, 0, 0, nullptr);
    R_ASSERT3(hSrcMap != INVALID_HANDLE_VALUE, cFileName, Debug.error2string(GetLastError()));

    data = static_cast<char*>(MapViewOfFile(hSrcMap, FILE_MAP_ALL_ACCESS, 0, 0, 0));
    R_ASSERT3(data, cFileName, Debug.error2string(GetLastError()));

#ifdef FS_DEBUG
    register_file_mapping(data, Size, cFileName);
#endif // DEBUG
}

CVirtualFileRW::~CVirtualFileRW() {
#ifdef FS_DEBUG
    unregister_file_mapping(data, Size);
#endif // DEBUG

    UnmapViewOfFile(data);
    CloseHandle(hSrcMap);
    CloseHandle(hSrcFile);
}

CVirtualFileReader::CVirtualFileReader(const char* cFileName) {
    // Open the file
    hSrcFile = CreateFile(cFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr,
                          OPEN_EXISTING, 0, nullptr);
    R_ASSERT3(hSrcFile != INVALID_HANDLE_VALUE, cFileName, Debug.error2string(GetLastError()));
    Size = static_cast<int>(GetFileSize(hSrcFile, nullptr));
    R_ASSERT3(Size, cFileName, Debug.error2string(GetLastError()));

    hSrcMap = CreateFileMapping(hSrcFile, nullptr, PAGE_READONLY, 0, 0, nullptr);
    R_ASSERT3(hSrcMap != INVALID_HANDLE_VALUE, cFileName, Debug.error2string(GetLastError()));

    data = static_cast<char*>(MapViewOfFile(hSrcMap, FILE_MAP_READ, 0, 0, 0));
    R_ASSERT3(data, cFileName, Debug.error2string(GetLastError()));

#ifdef FS_DEBUG
    register_file_mapping(data, Size, cFileName);
#endif // DEBUG
}

CVirtualFileReader::~CVirtualFileReader() {
#ifdef FS_DEBUG
    unregister_file_mapping(data, Size);
#endif // DEBUG

    UnmapViewOfFile(data);
    CloseHandle(hSrcMap);
    CloseHandle(hSrcFile);
}
