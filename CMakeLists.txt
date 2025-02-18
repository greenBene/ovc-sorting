cmake_minimum_required(VERSION 3.30)
project(OVCSorting)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/sort)
add_subdirectory(test)

## Main Executable
add_executable(${PROJECT_NAME} src/Main.cpp)
target_link_libraries(${PROJECT_NAME} sort)
