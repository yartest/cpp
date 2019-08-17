cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

message("Hello")

project(cpp_features)

set(CMAKE_CXX_STANDARD 14)

find_package (Threads)

file(GLOB_RECURSE 
    "*.h"
    "*.cpp"
)

set(SOURCE_EXE my_base_derived.cpp my_binary_unary_functions.cpp my_function_adapters.cpp
                my_initializer_list.cpp my_io_c.cpp my_io.cpp my_lambda.cpp my_list.cpp
                my_map.cpp my_pointers.cpp my_rvalue_lvalue.cpp my_string.cpp
                my_strongly_typed_enums.cpp my_test.cpp my_threads_one.cpp my_threads_two.cpp
                my_variadic_templates.cpp my_vector.cpp my_unordered_set.cpp stl.cpp)

add_executable(cpp_features ${SOURCE_EXE})
target_link_libraries (cpp_features ${CMAKE_THREAD_LIBS_INIT})