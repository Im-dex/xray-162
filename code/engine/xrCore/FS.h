// FS.h: interface for the CFS class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

static constexpr auto CFS_CompressMark = 1ul << 31ul;
static constexpr auto CFS_HeaderChunkID = 666;

XRCORE_API void createPath(const std::string_view path);

//#define FS_DEBUG

#ifdef FS_DEBUG
XRCORE_API extern u32 g_file_mapped_memory;
XRCORE_API extern u32 g_file_mapped_count;
XRCORE_API void dump_file_mappings();
extern void register_file_mapping(void* address, const u32& size, LPCSTR file_name);
extern void unregister_file_mapping(void* address, const u32& size);
#endif // DEBUG

//------------------------------------------------------------------------------------
// Write
//------------------------------------------------------------------------------------
class XRCORE_API IWriter {
    std::stack<size_t> chunk_pos;

public:
    std::string fName;

    IWriter() = default;
    virtual ~IWriter() {
        R_ASSERT3(chunk_pos.empty(), "Opened chunk not closed.", fName.c_str());
    }

    // kernel
    virtual void seek(const size_t pos) = 0;
    virtual size_t tell() = 0;

    virtual void w(const void* ptr, const size_t count) = 0;

    // generalized writing functions
    void w_u64(u64 d) { w(&d, sizeof(u64)); }
    void w_u32(u32 d) { w(&d, sizeof(u32)); }
    void w_u16(u16 d) { w(&d, sizeof(u16)); }
    void w_u8(u8 d) { w(&d, sizeof(u8)); }
    void w_s64(s64 d) { w(&d, sizeof(s64)); }
    void w_s32(s32 d) { w(&d, sizeof(s32)); }
    void w_s16(s16 d) { w(&d, sizeof(s16)); }
    void w_s8(s8 d) { w(&d, sizeof(s8)); }
    void w_float(float d) { w(&d, sizeof(float)); }
    void w_string(const char* p) {
        w(p, xr_strlen(p));
        w_u8(13);
        w_u8(10);
    }
    void w_stringZ(const char* p) { w(p, xr_strlen(p) + 1); }
    void w_stringZ(const shared_str& p) {
        w(*p ? *p : "", p.size());
        w_u8(0);
    }

    void w_stringZ(const std::string& p) {
        w(p.c_str(), p.size());
        w_u8(0);
    }

    void w_fcolor(const Fcolor& v) { w(&v, sizeof(Fcolor)); }
    void w_fvector4(const Fvector4& v) { w(&v, sizeof(Fvector4)); }
    void w_fvector3(const Fvector3& v) { w(&v, sizeof(Fvector3)); }
    void w_fvector2(const Fvector2& v) { w(&v, sizeof(Fvector2)); }
    void w_ivector4(const Ivector4& v) { w(&v, sizeof(Ivector4)); }
    void w_ivector3(const Ivector3& v) { w(&v, sizeof(Ivector3)); }
    void w_ivector2(const Ivector2& v) { w(&v, sizeof(Ivector2)); }

    // quant writing functions
    void w_float_q16(const float a, const float min, const float max) {
        VERIFY(a >= min && a <= max);
        const float q = (a - min) / (max - min);
        w_u16(u16(iFloor(q * 65535.f + .5f)));
    }

    void w_float_q8(const float a, const float min, const float max) {
        VERIFY(a >= min && a <= max);
        const float q = (a - min) / (max - min);
        w_u8(u8(iFloor(q * 255.f + .5f)));
    }

    void w_angle16(float a) { w_float_q16(angle_normalize(a), 0, PI_MUL_2); }
    void w_angle8(float a) { w_float_q8(angle_normalize(a), 0, PI_MUL_2); }
    void w_dir(const Fvector& D) { w_u16(pvCompress(D)); }
    void w_sdir(const Fvector& D);

    template <typename... Args>
    void w_printf(const char* format, const Args&... args) {
        static constexpr size_t bufSize = 1024;
        std::array<char, bufSize> buf;
        const auto written = std::snprintf(buf.data(), bufSize, format, args...);
        if (written > 0) {
            w(buf.data(), static_cast<size_t>(written));
        }
    }

    // generalized chunking
    void open_chunk(const u32 type);
    void close_chunk();
    size_t chunk_size(); // returns size of currently opened chunk, 0 otherwise
    void w_compressed(void* ptr, const size_t count);
    void w_chunk(const u32 type, void* data, const size_t size);
    virtual bool valid() { return true; }
    virtual void flush() = 0;
};

class XRCORE_API CMemoryWriter : public IWriter {
    u8* data;
    size_t position;
    size_t mem_size;
    size_t file_size;
public:
    CMemoryWriter()
        : data(nullptr),
          position(0),
          mem_size(0),
          file_size(0)
    {}
    virtual ~CMemoryWriter();

    // kernel
    void w(const void* ptr, const size_t count) override;

    void seek(const size_t pos) override { position = pos; }
    size_t tell() override { return position; }

    // specific
    u8* pointer() const { return data; }
    size_t size() const { return file_size; }
    void clear() {
        file_size = 0;
        position = 0;
    }

    void free() {
        file_size = 0;
        position = 0;
        mem_size = 0;
        xr_free(data);
    }

    bool save_to(const char* fn);
    void flush() override {}
};

//------------------------------------------------------------------------------------
// Read
//------------------------------------------------------------------------------------

template <typename implementation_type>
class IReaderBase {
public:
    IReaderBase() : m_last_pos(0) {}
    virtual ~IReaderBase() = default;

    implementation_type& impl() { return *static_cast<implementation_type*>(this); }
    const implementation_type& impl() const { return *static_cast<const implementation_type*>(this); }

    bool eof() const { return impl().elapsed() <= 0; }

    void r(void* p, const size_t cnt) { impl().r(p, cnt); }

    template <typename T>
    T r() {
        static_assert(std::is_trivial_v<T>, "T needs to be trivial type");
        T tmp;
        r(&tmp, sizeof(tmp));
        return tmp;
    }

    Fvector r_vec3() {
        return r<Fvector>();
    }

    Fvector4 r_vec4() {
        return r<Fvector4>();
    }

    u64 r_u64() {
        return r<u64>();
    }

    u32 r_u32() {
        return r<u32>();
    }

    u16 r_u16() {
        return r<u16>();
    }

    u8 r_u8() {
        return r<u8>();
    }

    s64 r_s64() {
        return r<s64>();
    }

    s32 r_s32() {
        return r<s32>();
    }

    s16 r_s16() {
        return r<s16>();
    }

    s8 r_s8() {
        return r<s8>();
    }

    float r_float() {
        return r<float>();
    }

    void r_fvector4(Fvector4& v) { r(&v, sizeof(Fvector4)); }
    void r_fvector3(Fvector3& v) { r(&v, sizeof(Fvector3)); }
    void r_fvector2(Fvector2& v) { r(&v, sizeof(Fvector2)); }
    void r_ivector4(Ivector4& v) { r(&v, sizeof(Ivector4)); }
    void r_ivector4(Ivector3& v) { r(&v, sizeof(Ivector3)); }
    void r_ivector4(Ivector2& v) { r(&v, sizeof(Ivector2)); }
    void r_fcolor(Fcolor& v) { r(&v, sizeof(Fcolor)); }

    float r_float_q16(const float min, const float max) {
        const auto val = r_u16();
        const float A = (float(val) * (max - min)) / 65535.f + min; // floating-point-error possible
        VERIFY((A >= min - EPS_S) && (A <= max + EPS_S));
        return A;
    }

    float r_float_q8(const float min, const float max) {
        const auto val = r_u8();
        const float A = (float(val) / 255.0001f) * (max - min) + min; // floating-point-error possible
        VERIFY((A >= min) && (A <= max));
        return A;
    }

    float r_angle16() { return r_float_q16(0, PI_MUL_2); }
    float r_angle8() { return r_float_q8(0, PI_MUL_2); }

    void r_dir(Fvector& A) {
        const auto t = r_u16();
        pvDecompress(A, t);
    }

    void r_sdir(Fvector& A) {
        const auto t = r_u16();
        float s = r_float();
        pvDecompress(A, t);
        A.mul(s);
    }
    // Set file pointer to start of chunk data (0 for root chunk)
    void rewind() { impl().seek(0); }

    size_t find_chunk(const u32 ID, bool* bCompressed = nullptr) {
        u32 dwType = 0;
        size_t dwSize = 0;

        bool success = false;
        if (m_last_pos != 0) {
            impl().seek(m_last_pos);
            dwType = r_u32();
            dwSize = r_u32();

            if ((dwType & (~CFS_CompressMark)) == ID) {
                success = true;
            }
        }

        if (!success) {
            rewind();
            while (!eof()) {
                dwType = r_u32();
                dwSize = r_u32();
                if ((dwType & (~CFS_CompressMark)) == ID) {
                    success = true;
                    break;
                } else {
                    impl().advance(dwSize);
                }
            }

            if (!success) {
                m_last_pos = 0;
                return 0;
            }
        }

        VERIFY(size_t(impl().tell()) + dwSize <= size_t(impl().length()));
        if (bCompressed)
            *bCompressed = dwType & CFS_CompressMark;

        const auto dwPos = impl().tell();
        if (dwPos + dwSize < size_t(impl().length())) {
            m_last_pos = dwPos + dwSize;
        } else {
            m_last_pos = 0;
        }

        return dwSize;
    }

    // чтение XR Chunk'ов (4b-ID,4b-size,??b-data)
    bool r_chunk(const u32 ID, void* dest) {
        const auto dwSize = impl().find_chunk(ID);
        if (dwSize != 0) {
            r(dest, dwSize);
            return true;
        } else
            return false;
    }

    // чтение XR Chunk'ов (4b-ID,4b-size,??b-data)
    bool r_chunk_safe(const u32 ID, void* dest, const size_t dest_size) {
        const auto dwSize = impl().find_chunk(ID);
        if (dwSize != 0) {
            R_ASSERT(dwSize == dest_size);
            r(dest, dwSize);
            return true;
        } else
            return false;
    }

private:
    size_t m_last_pos;
};

class XRCORE_API IReader : public IReaderBase<IReader> {
protected:
    char* data;
    int Pos;
    int Size;
    int iterpos;

public:
    IReader()
        : data(nullptr),
          Pos(0),
          Size(0),
          iterpos(0)
    {}

    virtual ~IReader() = default;

    IReader(void* data, const int size, const int iterpos = 0)
        : data(static_cast<char*>(data)),
          Pos(0),
          Size(size),
          iterpos(iterpos)
    {}

protected:
    size_t advance_term_string();

public:
    int elapsed() const { return Size - Pos; }
    int tell() const { return Pos; }
    void seek(const int ptr) {
        Pos = ptr;
        VERIFY((Pos <= Size) && (Pos >= 0));
    }
    int length() const { return Size; }
    void* pointer() const { return &(data[Pos]); }
    void advance(const int cnt) {
        Pos += cnt;
        VERIFY((Pos <= Size) && (Pos >= 0));
    }

    void r(void* p, const size_t cnt);

    void r_string(char* dest, const size_t tgt_sz);
    void r_string(std::string& dest);

    void skip_stringZ();

    void r_stringZ(char* dest, const size_t tgt_sz);
    void r_stringZ(shared_str& dest);
    void r_stringZ(std::string& dest);

    void close();

    // поиск XR Chunk'ов - возврат - размер или 0
    IReader* open_chunk(const u32 ID);

    // iterators
    IReader* open_chunk_iterator(u32& ID, IReader* previous = nullptr); // NULL=first
};

class XRCORE_API CVirtualFileRW : public IReader {
    void *hSrcFile, *hSrcMap;
public:
    CVirtualFileRW(const char* cFileName);
    virtual ~CVirtualFileRW();
};
