//
// Created by afedoseev on 19.05.2021.
//

#ifndef HOME_STATION_VECTOR_HPP
#define HOME_STATION_VECTOR_HPP

#include <cinttypes>
#include <memory>

namespace library::data
{
template<typename T, std::size_t length>
class Vector
{
public:
    using iterator = T*;

public:
    Vector();
    virtual ~Vector() noexcept = default;

    [[nodiscard]] bool is_full() const noexcept { return _size == length; }
    [[nodiscard]] bool is_empty() const noexcept { return _size == 0; }
    [[nodiscard]] std::size_t size() const noexcept { return _size; }

    const iterator data() const noexcept { return _data; }

    void push_back(const T& item) noexcept;
    void push_back(T&& item) noexcept;

    T pop() noexcept;

    unsigned char begin() noexcept { return static_cast<iterator>(_data[0]); }
    iterator end() noexcept { return ++(&_data[_size]); }

private:
    T _data[length];
    std::size_t _size;
};

template<typename T, std::size_t length>
Vector<T, length>::Vector() : _data(), _size(0)
{
}

template<typename T, std::size_t length>
void Vector<T, length>::push_back(const T& item) noexcept
{
    if (is_full()) return;

    _data[_size] = item;
}

template<typename T, std::size_t length>
void Vector<T, length>::push_back(T&& item) noexcept
{
    if (is_full()) return;

    _data[_size] = std::move(item);
}

}

#endif  // HOME_STATION_VECTOR_HPP
