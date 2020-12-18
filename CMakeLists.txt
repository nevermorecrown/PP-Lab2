cmake_minimum_required(VERSION 3.16)
project(RowCalculation)

set(CMAKE_CXX_STANDARD 20)

add_executable(RowCalculation config.h cpp_accumulator.cpp experiments.h interface.h
        num_threads.cpp num_threads.h omp_accumulator.c run_experiments.cpp main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")