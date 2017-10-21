#pragma once

// warning
// this function can be used for debug purposes only
template <typename... Args>
[[deprecated]]
std::string make_string(const char* format, const Args&... args) {
    static constexpr size_t kBufferSize = 4096;
    char temp[kBufferSize];
    snprintf(temp, kBufferSize, format, args...);
    return std::string(temp);
}

template <typename... Args>
std::string makeString(const char* format, const Args&... args) {
    XrWriter<4096> writer;
    writer.write(format, args);
    return writer.str();
}
