#pragma once

#include "stream_reader.h"

class CFileStreamReader : public CStreamReader {
    HANDLE m_file_handle;
public:
    virtual void construct(const char* file_name, const size_t window_size);
    void destroy() override;
};