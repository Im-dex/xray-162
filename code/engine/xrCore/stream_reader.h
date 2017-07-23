#pragma once

class XRCORE_API CStreamReader : public IReaderBase<CStreamReader> {
    HANDLE m_file_mapping_handle;
    size_t m_start_offset;
    size_t m_file_size;
    size_t m_archive_size;
    size_t m_window_size;

    size_t m_current_offset_from_start;
    size_t m_current_window_size;
    u8* m_current_map_view_of_file;
    u8* m_start_pointer;
    u8* m_current_pointer;

    void map(const size_t new_offset);
    void unmap() {
        UnmapViewOfFile(m_current_map_view_of_file);
    }

    void remap(const size_t new_offset) {
        unmap();
        map(new_offset);
    }

    // should not be called
    CStreamReader(const CStreamReader&) = delete;
    CStreamReader& operator=(const CStreamReader&) = delete;

public:
    CStreamReader() = default;

    virtual void construct(const HANDLE file_mapping_handle, const size_t start_offset,
                           const size_t file_size, const size_t archive_size, const size_t window_size);
    virtual void destroy() {
        unmap();
    }

    HANDLE file_mapping_handle() const {
        return m_file_mapping_handle;
    }

    size_t elapsed() const {
        const auto offset_from_file_start = tell();
        VERIFY(m_file_size >= offset_from_file_start);
        return m_file_size - offset_from_file_start;
    }

    size_t length() const {
        return m_file_size;
    }

    void seek(const int offset) {
        advance(offset - tell());
    }

    size_t tell() const {
        VERIFY(m_current_pointer >= m_start_pointer);
        VERIFY(size_t(m_current_pointer - m_start_pointer) <= m_current_window_size);
        return m_current_offset_from_start + (m_current_pointer - m_start_pointer);
    }

    // TODO: imdex note: pay attention!
    void close() {
        destroy();
        CStreamReader* self = this;
        xr_delete(self);
    }

    void advance(const int offset);
    void r(void* buffer, size_t buffer_size);
    CStreamReader* open_chunk(const size_t chunk_id);

    void r_stringZ(shared_str& dest);
};