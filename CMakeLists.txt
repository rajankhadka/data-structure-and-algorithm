cmake_minimum_required(VERSION 3.22)
project(data-structure-and-algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(dsa main.cpp)
add_executable(problem05 ./problem/remove-duplicate-node-unsorted-singly-linked-list.problem.cpp)
add_executable(problem06 ./problem/find-loop-singly-linked-list.problem.cpp)
add_executable(problem07 ./problem/sum-of-two-linked-list.problem.cpp)