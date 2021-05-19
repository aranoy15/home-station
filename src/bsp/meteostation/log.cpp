//
// Created by afedoseev on 18.05.2021.
//

#include <bsp.hpp>
#include <csp.hpp>

void bsp::log::init()
{
    csp::usb::cdc::init();
}

void bsp::log::transmit(const uint8_t *data, std::size_t size)
{
    csp::usb::cdc::transmit(data, size);
}

bool bsp::log::receive(uint8_t *data, std::size_t size)
{
    return csp::usb::cdc::receive(data, size);
}
