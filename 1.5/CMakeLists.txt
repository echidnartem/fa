cmake_minimum_required(VERSION 3.10)
project(flags_program C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(flags_program 
    main.c 
    source/functions.c
    source/usage.c
    source/validation.c
)

target_include_directories(flags_program  PRIVATE)

target_link_libraries(flags_program  m)