//
// Created by afedoseev on 18.05.2021.
//

#include <csp_template.hpp>
//#include <gpio.h>
#include <main.h>

void csp::init()
{
    HAL_Init();
    SystemClock_Config();

    //MX_GPIO_Init();
}
