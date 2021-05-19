//
// Created by afedoseev on 19.05.2021.
//

#ifndef HOME_STATION_QUEUE_HPP
#define HOME_STATION_QUEUE_HPP

#include <queue_template.hpp>
#include <data/queue.hpp>

namespace os::queue
{
template<typename T, std::size_t length>
using queue_t = library::data::Queue<T, length>;
}

#endif  // HOME_STATION_QUEUE_HPP
