//
// Created by afedoseev on 18.05.2021.
//

#ifndef HOME_STATION_LOG_HPP
#define HOME_STATION_LOG_HPP

#include <cinttypes>

namespace bsp::log
{
void init();
void transmit(const uint8_t data[], std::size_t size);
bool receive(uint8_t data[], std::size_t size);
}

#endif  // HOME_STATION_LOG_HPP
