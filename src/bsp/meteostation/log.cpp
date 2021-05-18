//
// Created by afedoseev on 18.05.2021.
//

#include <csp.hpp>
#include <bsp.hpp>

void bsp::log::init()
{
    csp::usb::cdc::init();
}

void bsp::log::transmit(const uint8_t *data, std::size_t size)
{
    csp::usb::cdc::transmit(data, size);
}
