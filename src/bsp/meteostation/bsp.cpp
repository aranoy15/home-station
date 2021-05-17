//
// Created by Антон Федосеев on 16.05.2021.
//

#include <bsp.hpp>
#include <main.h>
#include <usb_device.h>
#include <usbd_cdc_if.h>

void bsp::init()
{
    HAL_Init();

    SystemClock_Config();

    MX_USB_DEVICE_Init();

    uint8_t packet[] = "Hello world!\r\n";

    CDC_Transmit_FS(packet, sizeof(packet));
}
