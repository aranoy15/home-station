
add_executable(app
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )

set_property(TARGET app PROPERTY INTERPROCEDURAL_OPTIMIZATION True)

target_link_libraries(app PRIVATE
        BSP::METEOSTATION
        )

stm32_add_linker_script(app PRIVATE
        ${CMAKE_SOURCE_DIR}/src/toolchain/linker/ST/F103C8/gcc/app/link.ld
        )

add_custom_target(app.generate_bin ALL
        ${STM32_TARGET_TRIPLET}-objcopy -Obinary ${CMAKE_BINARY_DIR}/src/app/app.elf ${CMAKE_BINARY_DIR}/app.bin
        DEPENDS app
        )

add_custom_target(app.size ALL
        ${STM32_TARGET_TRIPLET}-size ${CMAKE_BINARY_DIR}/src/app/app.elf
        DEPENDS boot
        )
