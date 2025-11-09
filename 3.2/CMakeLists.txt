cmake_minimum_required(VERSION 3.10)
project(vector_tests C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(include)

add_executable(vector_int_test
    testing/vector_int.c
)

add_executable(vector_string_test
    testing/vector_string.c
)

add_executable(vector_double_test
    testing/vector_double.c
)

target_link_libraries(vector_int_test m)
target_link_libraries(vector_string_test m)
target_link_libraries(vector_double_test m)
