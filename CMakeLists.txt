cmake_minimum_required(VERSION 3.30)
project(OVCSorting)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(src/sort)
add_subdirectory(test)

find_package(Boost 1.87.0 REQUIRED
  COMPONENTS program_options
)

## Main Executable
add_executable(${PROJECT_NAME} src/Main.cpp)
target_link_libraries(${PROJECT_NAME}
        sort
        Boost::program_options
)
