cmake_minimum_required(VERSION 3.10)
project(managing_threads)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(managing_threads #[[main.cpp]] #[[function_param.cpp]] #[[scoped_thread.cpp]] #[[joining_thread.h]]
        #[[parallel_accumulate.cpp]] thread_id.cpp)
target_link_libraries(managing_threads PRIVATE Threads::Threads)
