## Setup Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        ${PROJECT_NAME}Test
        AOVCTest.cpp
        HeapsortTest.cpp
        HeapsortOVCTest.cpp
        InsertionSortTest.cpp
        InsertionSortOVCTest.cpp
        InsertionSortAOVCTest.cpp
        MergesortTest.cpp
        MergesortOVCTest.cpp
        QuicksortTest.cpp
        QuicksortOVCTest.cpp
        QuicksortAOVCTest.cpp
        OVCTest.cpp
        Utils.h
)

target_link_libraries(
        ${PROJECT_NAME}Test
        GTest::gtest_main
        sort
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}Test)