
add_library(bsp_meteostation INTERFACE)

target_include_directories(bsp_meteostation INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/../share/
)

target_sources(bsp_meteostation INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/bsp.cpp
)

target_link_libraries(bsp_meteostation INTERFACE
    CSP::F103xB::METEOSTATION
)

add_library(BSP::METEOSTATION ALIAS bsp_meteostation)
