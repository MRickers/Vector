cmake_minimum_required(VERSION 3.10)
project(vectorlib CXX)

if(WIN32)
set(COMPILE_OPTIONS)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
include(InstallRequiredSystemLibraries)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
else()
set(CMAKE_CXX_STANDARD 17)
set(COMPILE_OPTIONS -Wall -Wextra -pedantic -Werror)
endif()

option(build_example "Building examples" ON)

add_library(${PROJECT_NAME} STATIC src/vector2d.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

if(build_example)
add_executable(vectortest examples/vector2dtest.cpp)
target_include_directories(vectortest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(vectortest ${PROJECT_NAME})
target_compile_options(vectortest PRIVATE ${COMPILE_OPTIONS})
install(TARGETS vectortest DESTINATION bin RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
endif()