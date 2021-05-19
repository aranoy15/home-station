
add_library(library_data INTERFACE)

target_include_directories(library_data INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/../
        )

add_library(LIBRARY::DATA ALIAS library_data)
