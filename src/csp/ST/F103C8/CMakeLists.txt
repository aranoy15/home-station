
set(STM32_CUBE_F1_PATH ${CMAKE_SOURCE_DIR}/src/toolchain/ST/STM32CubeF1-1.8.3)

find_package(CMSIS COMPONENTS STM32F1 REQUIRED)
find_package(HAL COMPONENTS STM32F1 I2C RCC GPIO CORTEX TIM FLASH UART USART DMA PCD LL_USB REQUIRED)

add_library(csp_f103xb_meteostation_core INTERFACE)
add_library(csp_f103xb_meteostation_usb INTERFACE)

target_include_directories(csp_f103xb_meteostation_core INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../../share
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_include_directories(csp_f103xb_meteostation_usb INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../../share
        ${CMAKE_CURRENT_SOURCE_DIR}/src/USB_DEVICE/App
        ${CMAKE_CURRENT_SOURCE_DIR}/src/USB_DEVICE/Target
        ${STM32_CUBE_F1_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Inc
        ${STM32_CUBE_F1_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc

        )

target_sources(csp_f103xb_meteostation_core INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Src/rcc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Src/gpio.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Src/stm32f1xx_hal_msp.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Src/stm32f1xx_hal_timebase_tim.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Src/stm32f1xx_it.c

        ${CMAKE_CURRENT_SOURCE_DIR}/csp.cpp
        )

target_sources(csp_f103xb_meteostation_usb INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/USB_DEVICE/App/usb_device.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/USB_DEVICE/App/usbd_cdc_if.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/USB_DEVICE/App/usbd_desc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/USB_DEVICE/Target/usbd_conf.c
        ${STM32_CUBE_F1_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/src/usbd_cdc.c
        ${STM32_CUBE_F1_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c
        ${STM32_CUBE_F1_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c
        ${STM32_CUBE_F1_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c

        ${CMAKE_SOURCE_DIR}/src/csp/ST/share/usb.cpp
        )

target_link_libraries(csp_f103xb_meteostation_core INTERFACE
        HAL::STM32::F1::RCC
        HAL::STM32::F1::RCCEx
        HAL::STM32::F1::CORTEX
        HAL::STM32::F1::GPIO
        HAL::STM32::F1::FLASH
        HAL::STM32::F1::FLASHEx
        HAL::STM32::F1::TIM
        HAL::STM32::F1::TIMEx
        CMSIS::STM32::F103xB
        STM32::NoSys

        OS::NO_OS
        )

target_link_libraries(csp_f103xb_meteostation_usb INTERFACE
        HAL::STM32::F1::PCD
        HAL::STM32::F1::PCDEx
        HAL::STM32::F1::LL_USB
)

target_compile_definitions(csp_f103xb_meteostation_usb INTERFACE
        -DUSE_USB
        )

add_library(CSP::F103xB::METEOSTATION::CORE ALIAS csp_f103xb_meteostation_core)
add_library(CSP::F103xB::METEOSTATION::USB ALIAS csp_f103xb_meteostation_usb)
