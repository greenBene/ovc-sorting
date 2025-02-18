add_library(
        sort
        Sort.cpp
        InsertionSort.cpp
)

target_include_directories(sort
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)