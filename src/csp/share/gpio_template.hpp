//
// Created by afedoseev on 19.05.2021.
//

#ifndef HOME_STATION_GPIO_TEMPLATE_HPP
#define HOME_STATION_GPIO_TEMPLATE_HPP

namespace csp::gpio
{
enum class Number
{
    _0 = 0,
    _1,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,
    _10,
    _11,
    _12,
    _13,
    _14,
    _15,
    _16,
    _17,
    _18,
    _19,
    _20,
    _21,
    _22,
    _23,
    _24,
    _25,
    _26,
    _27,
    _28,
    _29,
    _30,
    _31,
    _32,
};

using number_t = Number;

void init(number_t number);
void on(number_t number);
void off(number_t number);
void toggle(number_t number);
bool state(number_t number);
}

#endif  // HOME_STATION_GPIO_TEMPLATE_HPP
