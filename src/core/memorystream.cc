//
// Created by moreal-gram on 2018-08-29.
//

#include "memorystream.h"

void MemoryStream::ReallocBuffer(uint32_t newLength) {
    m_buffer = static_cast<char*>(std::realloc(m_buffer, newLength));
    m_capacity = newLength;
}

template<typename T>
void MemoryStream::Write(const T &data) {
    static_assert(
            std::is_arithmetic<T>::value ||
            std::is_enum<T>::value,
            "Generic Write only supports primitive data types");

    Write(&data, sizeof(data));
}

template<typename T>
void MemoryStream::Write(const T* data, size_t size) {
    uint32_t newHead = m_head + static_cast<uint32_t>(size);

    if (newHead > m_capacity) ReallocBuffer(std::max(newHead, m_capacity * 2));

    std::memcpy(m_buffer, m_head, data, size);
}

template<typename T>
void MemoryStream::Read(const T &data) {
    std::memcpy(&data, sizeof(data), m_buffer, m_head);
}