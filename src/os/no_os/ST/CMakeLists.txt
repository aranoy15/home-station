
add_library(no_os INTERFACE)

target_sources(no_os INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/os.cpp
        )

target_include_directories(no_os INTERFACE
        ${CMAKE_SOURCE_DIR}/src/os/share
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_link_libraries(no_os INTERFACE
        CSP::F103xB::METEOSTATION::CORE
        LIBRARY::DATA
        )

add_library(OS::NO_OS ALIAS no_os)
