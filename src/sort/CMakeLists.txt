add_library(
        sort
        Heapsort.cpp
        InsertionSort.cpp
        InsertionSortOVC.cpp
        InsertionSortAOVC.cpp
        Quicksort.cpp
        QuicksortOVC.cpp
        QuicksortAOVC.cpp
)

target_include_directories(sort
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)