cmake_minimum_required(VERSION 3.10)
project(fractions_program C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(fractions_program 
    main.c 
    source/mathf.c
    source/fractions.c
)

target_include_directories(fractions_program  PRIVATE)

target_link_libraries(fractions_program  m)