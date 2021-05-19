//
// Created by afedoseev on 19.05.2021.
//

#ifndef HOME_STATION_LIBRARY_QUEUE_HPP
#define HOME_STATION_LIBRARY_QUEUE_HPP

#include <cinttypes>

namespace library::data
{
template <typename T, std::size_t length>
class Queue
{
public:
    Queue();
    ~Queue() noexcept = default;

    void put(const T& item) noexcept;

    T pop() noexcept;
    // void clear() noexcept;

    [[nodiscard]] bool is_full() const noexcept { return _is_full; }

    [[nodiscard]] bool is_empty() const noexcept
    {
        return (not is_full() and (_head == _tail));
    }

    void clear() noexcept
    {
        _head = _tail;
        _is_full = false;
    }

    [[nodiscard]] std::size_t capacity() const noexcept { return length; }
    [[nodiscard]] std::size_t size() const noexcept;


    // std::size_t capacity() const noexcept { return length; }
    // std::size_t size() const noexcept;

private:
    T _data[length];
    std::size_t _head = 0;
    std::size_t _tail = 0;
    bool _is_full = false;
};

template <typename T, std::size_t length>
Queue<T, length>::Queue() : _data(), _head(0), _tail(0), _is_full(false)
{
}


template <typename T, std::size_t length>
void Queue<T, length>::put(const T& item) noexcept
{
    _data[_head] = item;

    if (is_full()) {
        _tail = (_tail + 1) % length;
    }

    _head = (_head + 1) % length;
    _is_full = _head == _tail;
}

template <typename T, std::size_t length>
T Queue<T, length>::pop() noexcept
{
    if (is_empty()) return T();

    T result = _data[_tail];
    _is_full = false;
    _tail = (_tail + 1) % length;

    return result;
}

template <typename T, std::size_t length>
std::size_t Queue<T, length>::size() const noexcept
{
    std::size_t size = length;

    if (not is_full()) {
        if (_head >= _tail) size = _head - _tail;
        else size = length + _head - _tail;
    }

    return size;
}
}  // namespace library::data

#endif  // HOME_STATION_LIBRARY_QUEUE_HPP
