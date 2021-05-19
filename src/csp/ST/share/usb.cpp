//
// Created by afedoseev on 18.05.2021.
//

#include <csp_template.hpp>
#include <main.h>
#include <os.hpp>
#include <usb_device.h>
#include <usbd_cdc_if.h>

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

using queue_t = os::queue::queue_t<uint8_t, 1024>;
queue_t usb_buffer;

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
    if (usb_buffer.is_empty()) return false;
    if (usb_buffer.size() < size) return false;

    for (std::size_t i = 0; i < size; ++i) {
        uint8_t b = usb_buffer.pop();
        data[i] = b;
    }

    return true;
}

extern "C" {
void CDC_Receive_FS_Callback(uint8_t* Buf, uint16_t Len)
{
    for (uint16_t i = 0; i < Len; ++i) {
        usb_buffer.put(Buf[i]);
    }
}
}
