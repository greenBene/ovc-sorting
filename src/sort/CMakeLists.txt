add_library(
        sort
        InsertionSort.cpp
        InsertionSortOVC.cpp
)

target_include_directories(sort
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)