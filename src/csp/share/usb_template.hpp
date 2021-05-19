//
// Created by afedoseev on 18.05.2021.
//

#ifndef HOME_STATION_USB_TEMPLATE_HPP
#define HOME_STATION_USB_TEMPLATE_HPP

#include <cinttypes>

namespace csp::usb::cdc
{
void init();
bool poll();

void transmit(const uint8_t data[], std::size_t size);
bool receive(uint8_t data[], std::size_t size);
}

#endif  // HOME_STATION_USB_TEMPLATE_HPP
