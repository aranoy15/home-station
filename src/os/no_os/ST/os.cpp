//
// Created by afedoseev on 18.05.2021.
//

#include <os.hpp>
#include <main.h>

void os::init() {}

void os::tick::delay(uint32_t timeout)
{
    HAL_Delay(timeout);
}

uint32_t os::tick::current()
{
    return HAL_GetTick();
}


