//
// Created by Антон Федосеев on 16.05.2021.
//

#include <bsp.hpp>
#include <os.hpp>

int main()
{
    bsp::init();
    bsp::log::init();

    [[maybe_unused]] const uint8_t data[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '\r', '\n'};

    [[maybe_unused]] uint32_t start = os::tick::current();

    while(true) {
        if ((os::tick::current() - start) >= 1000) {
            bsp::log::transmit(data, sizeof(data));
            start = os::tick::current();
        }
        //os::tick::delay(1000);

    }
}
