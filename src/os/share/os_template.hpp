//
// Created by afedoseev on 18.05.2021.
//

#ifndef HOME_STATION_OS_TEMPLATE_HPP
#define HOME_STATION_OS_TEMPLATE_HPP

#include <cinttypes>

namespace os
{
void init();

namespace tick
{
    void delay(uint32_t timeout);
    uint32_t current();
}
}

#endif  // HOME_STATION_OS_TEMPLATE_HPP
