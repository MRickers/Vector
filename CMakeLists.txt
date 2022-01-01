cmake_minimum_required(VERSION 3.21)
project(Vector CXX)

if(WIN32)
set(COMPILE_OPTIONS)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

else()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
set(COMPILE_OPTIONS -Wall -Wextra -pedantic -Werror)
endif()

option(build_example "Building examples" ON)

add_library(vector SHARED src/vector2d.cpp)

target_include_directories(vector PUBLIC include)
target_compile_options(vector PRIVATE ${COMPILE_OPTIONS})
install(TARGETS vector DESTINATION bin)

if(build_example)
add_executable(vectortest examples/vector2dtest.cpp)
target_include_directories(vectortest PUBLIC include)
target_link_libraries(vectortest vector)
target_compile_options(vectortest PRIVATE ${COMPILE_OPTIONS})
install(TARGETS vectortest DESTINATION bin)
endif()