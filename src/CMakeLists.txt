cmake_minimum_required(VERSION 3.25.1)

project(cpp_unions VERSION 0.2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")


if (UNIX)
    add_compile_options("$<$<CONFIG:RelWithDebInfo>:-O2>" "$<$<CONFIG:RelWithDebInfo>:-fsanitize=address>")
    add_link_options("$<$<CONFIG:RelWithDebInfo>:-fsanitize=address>")
endif(UNIX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO  "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(unions)
add_subdirectory(tests)

