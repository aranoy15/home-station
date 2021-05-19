//
// Created by Антон Федосеев on 16.05.2021.
//

#include <bsp.hpp>
#include <os.hpp>
#include <data/vector.hpp>

int main()
{
    bsp::init();
    bsp::log::init();

    const uint8_t data[] = {'H', 'e', 'l', 'l', 'o', ',', ' ',
                            'W', 'o', 'r', 'l', 'd', '\n'};

    uint32_t start = os::tick::current();

    using data_t = library::data::Vector<uint8_t, 1024>;

    data_t output_data;
    uint8_t temp_data[1] = {0};

    while (true) {
        if ((os::tick::current() - start) >= 1000) {
            bsp::log::transmit(data, sizeof(data));
            start = os::tick::current();
        }

        if (bsp::log::receive(temp_data, sizeof(temp_data))) {
            //bsp::log::transmit(temp_data, sizeof(temp_data));
            output_data.push_back(temp_data[0]);
        }
    }
}
