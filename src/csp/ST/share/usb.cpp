//
// Created by afedoseev on 18.05.2021.
//

#include <main.h>
#include <csp.hpp>
#include <usbd_cdc_if.h>
#include <usb_device.h>

extern USBD_HandleTypeDef hUsbDeviceFS;

namespace
{
USBD_CDC_HandleTypeDef* hcdc()
{
    return static_cast<USBD_CDC_HandleTypeDef*>(hUsbDeviceFS.pClassData);
}

bool is_initialize()
{
    return hcdc() != NULL;
}
}

void csp::usb::cdc::init()
{
    MX_USB_DEVICE_Init();
}

bool csp::usb::cdc::poll()
{
    if (not is_initialize()) {
        return true;
    }

    return (hcdc()->TxState == 0 and hcdc()->RxState == 0);
}

void csp::usb::cdc::transmit(const uint8_t data[], std::size_t size)
{
    CDC_Transmit_FS(const_cast<uint8_t*>(data), size);

    while (!poll()) {}
}

bool csp::usb::cdc::receive(uint8_t data[], std::size_t size)
{
    (void)data;
    (void)size;

    return false;
}

extern "C" {
void CDC_Receive_FS_Callback(uint8_t* Buf, uint16_t Len)
{
    int t = 0;
}
}
