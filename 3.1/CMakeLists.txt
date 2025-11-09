cmake_minimum_required(VERSION 3.10)
project(bits_program C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(bits_program 
    main.c 
    source/function.c
    testing/tests.c
)

target_include_directories(bits_program  PRIVATE)

target_link_libraries(bits_program  m)