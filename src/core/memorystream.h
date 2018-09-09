//
// Created by moreal-gram on 2018-08-29.
//

#ifndef WSL_MEMORYSTREAM_H
#define WSL_MEMORYSTREAM_H

#include <cstdint>
#include <cstring>
#include <algorithm>

class MemoryStream {
public:
    MemoryStream& operator =(const MemoryStream&) = delete;
    MemoryStream(const MemoryStream&) = delete;

    MemoryStream() : m_buffer(nullptr), m_head(0), m_capacity(0) {
        m_buffer = static_cast<char*>(std::malloc(m_capacity));
    }
    ~MemoryStream() { delete m_buffer; }

    inline const char* GetBufferPtr() const { return m_buffer; }
    inline uint32_t GetLength() const { return m_head; }

    void ReallocBuffer(uint32_t);

    template<typename T>
    void Write(const T*, size_t);

    template <typename T>
    void Write(const T&);

    template <typename T>
    void Read(const T&);

private:
    char* m_buffer;
    uint32_t m_head;
    uint32_t m_capacity;
};


#endif //WSL_MEMORYSTREAM_H
