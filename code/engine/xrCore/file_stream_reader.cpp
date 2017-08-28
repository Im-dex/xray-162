#include "stdafx.h"
#include "file_stream_reader.h"

void CFileStreamReader::construct(const char* file_name, const size_t window_size) {
    m_file_handle = CreateFile(file_name, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);

    VERIFY(m_file_handle != INVALID_HANDLE_VALUE);
    const auto file_size = size_t(GetFileSize(m_file_handle, nullptr));

    auto file_mapping_handle = CreateFileMapping(m_file_handle, nullptr, PAGE_READONLY, 0, 0, nullptr);
    VERIFY(file_mapping_handle != INVALID_HANDLE_VALUE);

    __super::construct(file_mapping_handle, 0, file_size, file_size, window_size);
}

void CFileStreamReader::destroy() {
    auto file_mapping_handle = this->file_mapping_handle();
    __super::destroy();
    CloseHandle(file_mapping_handle);
    CloseHandle(m_file_handle);
}
