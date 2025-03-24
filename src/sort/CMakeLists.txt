add_library(
        sort
        Heapsort.cpp
        HeapsortOVC.cpp
        InsertionSort.cpp
        InsertionSortOVC.cpp
        InsertionSortAOVC.cpp
        Mergesort.cpp
        Quicksort.cpp
        QuicksortOVC.cpp
        QuicksortAOVC.cpp
)

target_include_directories(sort
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)