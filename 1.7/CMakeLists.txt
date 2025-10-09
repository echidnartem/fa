cmake_minimum_required(VERSION 3.10)
project(files_program C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(files_program 
    main.c 
    source/functions.c
)

target_include_directories(files_program  PRIVATE)

target_link_libraries(files_program  m)