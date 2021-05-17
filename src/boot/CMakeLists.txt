
add_executable(boot
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set_property(TARGET boot PROPERTY INTERPROCEDURAL_OPTIMIZATION True)

target_link_libraries(boot PRIVATE
    BSP::METEOSTATION
)

stm32_add_linker_script(boot PRIVATE
    ${CMAKE_SOURCE_DIR}/src/toolchain/linker/ST/F103C8/gcc/boot/link.ld
)

add_custom_target(boot.generate_bin ALL
    ${STM32_TARGET_TRIPLET}-objcopy -Obinary ${CMAKE_BINARY_DIR}/src/boot/boot.elf ${CMAKE_BINARY_DIR}/boot.bin
    DEPENDS boot
)

add_custom_target(${TARGET}.size ALL
    ${STM32_TARGET_TRIPLET}-size ${CMAKE_BINARY_DIR}/src/boot/boot.elf
    DEPENDS boot
)
