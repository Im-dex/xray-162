#pragma once
#include "hxgrid/Interface/IAgent.h"

class XRLC_LIGHT_API byte_count {
    size_t _count;
public:
    byte_count() : _count(0) {}
    size_t count() const { return _count; }
    void reset() { _count = 0; }
    void add(const size_t cnt) { _count += cnt; }
};

class CReadMemoryBlock {
    mutable size_t file_size;
    mutable u8* _buffer;
    const u32 buf_size;
    mutable u32 position;

public:
    CReadMemoryBlock(const size_t buf_size_, u8* buffer);
    ~CReadMemoryBlock();
    void r(void* p, const size_t cnt) const;
    size_t count() const { return file_size - position; }
    void* pdata() const { return static_cast<void*>(_buffer); }

    void free_buff() const {
        file_size = 0;
        position = 0;
    }

    void alloc(const size_t _file_size) const {
        R_ASSERT(buf_size >= _file_size);
        VERIFY(!allocated());
        VERIFY(empty());
        file_size = _file_size;
    }
    bool allocated() const { return file_size != 0; }
    bool empty() const { return position == 0; }
};

class IReadBlock {
public:
    virtual void r(void* p, const size_t cnt) const = 0;
    virtual size_t count() const = 0;
    virtual void* pdata() const = 0;
};

class IWriteBlock {
protected:
    size_t size;

public:
    virtual ~IWriteBlock() = default;
    IWriteBlock(const size_t size) : size(size) {}
    virtual bool save_to(const char* fn) = 0;
    virtual void w(const void* ptr, const size_t count) = 0;
    virtual void send(IGenericStream* stream) = 0;
    virtual size_t rest() = 0;
};

class CMemoryWriteBlock {
    u8* buffer;
    const size_t buffer_size;
    size_t position;
public:
    CMemoryWriteBlock(u8* buffer, const size_t size) : buffer(buffer), buffer_size(size), position(0) {}

    void send(IGenericStream* _stream);
    size_t rest() { return buffer_size - tell(); }
    void w(const void* ptr, const size_t count);

    void clear() { position = 0; }
    bool is_empty() const { return 0 == position; }

private:
    size_t tell() const { return position; }
    u8* pointer() const { return buffer; }
};

class CFileWriteBlock : public IWriteBlock {
    FILE* file;
    FILE* file_map;
    const char* file_name;
    bool reopen;
public:
    CFileWriteBlock(const char* fn, const size_t size, const bool reopen);
    ~CFileWriteBlock();
    bool save_to(const char* fn) override { return false; };
    void send(IGenericStream* stream) override;
    size_t rest() override;
    void w_close();
    void w(const void* ptr, const size_t count) override;
};

class XRLC_LIGHT_API INetReader : public IReaderBase<INetReader>,
                                  public byte_count

{
public:
    INetReader() {
        // VERIFY(stream);
    }
    virtual ~INetReader();
    int elapsed() const {
        VERIFY(false);
        return 0;
    }

    void seek(const size_t pos) { VERIFY(false); };

    int tell() const {
        VERIFY(false);
        return 0;
    }

    int length() const {
        VERIFY(false);
        return 0;
    }

    void advance(const int cnt) { VERIFY(false); }

    virtual void r(void* p, const size_t cnt) = 0;

    void r_string(char* dest, const size_t tgt_sz);
    void r_stringZ(char* dest);
    void r_stringZ(shared_str& dest);
    size_t find_chunk(const u32 ID, bool* bCompressed = nullptr);
};

class XRLC_LIGHT_API INetReaderFile : public INetReader {
    FILE* file;

public:
    INetReaderFile(const char* file);

    virtual ~INetReaderFile();

private:
    void r(void* p, const size_t cnt) override;
};
//////////////////////////////////////////////////////////////////////////////
class XRLC_LIGHT_API INetBuffWriter : public IWriter, public byte_count {
protected:
    IWriteBlock* mem_writter;
private:
    void seek(const size_t) override { VERIFY(false); }

    size_t tell() override {
        VERIFY(false);
        return 0;
    }

    void flush() override { VERIFY(false); }

public:
    INetBuffWriter() : mem_writter(nullptr) {
        // VERIFY(stream);
    }
    virtual ~INetBuffWriter();

    virtual void send_not_clear(IGenericStream* _stream);
    virtual void clear();
    virtual void save_buffer(const char* fn) const;
};
class XRLC_LIGHT_API INetMemoryBuffWriter : public IWriter,
                                            public byte_count {
    IGenericStream* stream;
    size_t net_block_write_data_size;
    CMemoryWriteBlock mem_writter;
public:
    INetMemoryBuffWriter(IGenericStream* stream, const size_t block_size, u8* buffer)
        : stream(stream), net_block_write_data_size(block_size),
          mem_writter(buffer, block_size) {
        // VERIFY(stream);
    }
    ~INetMemoryBuffWriter();

private:
    void w(const void* ptr, const size_t count) override;
    void send_and_clear();

    void seek(const size_t pos) override { VERIFY(false); }

    size_t tell() override {
        VERIFY(false);
        return 0;
    }

    void flush() override { VERIFY(false); }
};

class XRLC_LIGHT_API INetReaderGenStream : public INetReader {
public:
    INetReaderGenStream(IGenericStream* _stream) : stream(_stream) {}
    virtual ~INetReaderGenStream();

protected:
    IGenericStream* stream;

private:
    void r(void* p, const size_t cnt) override;
};

class XRLC_LIGHT_API INetIWriterGenStream : public IWriter {
    IGenericStream* stream;
    size_t block_size;
public:
    INetIWriterGenStream(IGenericStream* stream, const size_t inital_size);
    virtual ~INetIWriterGenStream() = default;

private:
    void w(const void* ptr, const size_t count) override;
    void seek(const size_t) override { VERIFY(false); }

    size_t tell() override {
        VERIFY(false);
        return 0;
    }

    void flush() override { VERIFY(false); }
};

class XRLC_LIGHT_API INetBlockReader : public INetReaderGenStream {
    CReadMemoryBlock mem_reader;

public:
    INetBlockReader(IGenericStream* stream, u8* buffer, const size_t size_buffer)
        : INetReaderGenStream(stream), mem_reader(size_buffer, buffer) {}

    void load_buffer(const char* fn);
    void r(void* p, const size_t cnt) override;
    virtual ~INetBlockReader();

private:
    void create_block(const size_t size);
};

////////////////////////////////////////////////////////////////////////////////////

class CGenStreamOnFile : public IGenericStream {
    CVirtualFileRW* file;
public:
    CGenStreamOnFile(CVirtualFileRW* _file);
    ~CGenStreamOnFile();

private:
    //======== BEGIN COM INTERFACE =======
    IUNKNOWN_METHODS_IMPLEMENTATION_INSTANCE()

    virtual BYTE* __stdcall GetBasePointer() { return (BYTE*)file->pointer(); }
    virtual BYTE* __stdcall GetCurPointer() {
        R_ASSERT(false);
        return nullptr;
    }
    virtual bool __stdcall isReadOnly() {
        R_ASSERT(false);
        return false;
    }
    virtual DWORD __stdcall GetLength();
    virtual void __stdcall Write(const void* Data, DWORD count) { R_ASSERT(false); }
    virtual DWORD __stdcall Read(void* Data, DWORD count);
    virtual void __stdcall Seek(DWORD pos) { R_ASSERT(false); }
    virtual DWORD __stdcall GetPos() {
        R_ASSERT(false);
        return false;
    }
    virtual void __stdcall Clear() { R_ASSERT(false); }
    virtual void __stdcall FastClear() { R_ASSERT(false); }
    virtual void __stdcall GrowToPos(int DestSize = -1) { R_ASSERT(false); }
    virtual void __stdcall Skip(DWORD count) { R_ASSERT(false); }
    virtual void __stdcall SetLength(DWORD newLength) { R_ASSERT(false); }
    virtual void __stdcall Compact() { R_ASSERT(false); }
    virtual DWORD __stdcall GetVersion() const { return CGenStreamOnFile::VERSION; }
};
