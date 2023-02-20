cmake_minimum_required(VERSION 3.2)
project(FireStone)

set(CMAKE_Application_STANDARD 23)

file(GLOB_RECURSE FireStone_Application_Sources "Application/*.cxx" "Application/*.hxx")

add_executable(FireStone ${FireStone_Application_Sources})
