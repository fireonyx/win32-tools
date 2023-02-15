cmake_minimum_required(VERSION 3.2)
project(Rayonix_Win32Tools)

set(CMAKE_CXX_STANDARD 23)

# Add control flow library
file(GLOB_RECURSE Rayonix_Win32Tools_ControlFlow_Files "ControlFlow/*.cxx")
file(GLOB_RECURSE Rayonix_Win32Tools_ControlFlow_Headers "ControlFlow/*.hxx")

add_library(Rayonix_Win32Tools_ControlFlow ${Rayonix_Win32Tools_ControlFlow_Files} ${Rayonix_Win32Tools_ControlFlow_Headers})

# Add entry program
file(GLOB_RECURSE Rayonix_Win32Tools_Entry_Files "Entry/*.cxx")
file(GLOB_RECURSE Rayonix_Win32Tools_Entry_Headers "Entry/*.hxx")

add_executable(win32tools_bin ${Rayonix_Win32Tools_Entry_Files} ${Rayonix_Win32Tools_Entry_Headers})

target_link_libraries(win32tools_bin ${Rayonix_Win32Tools_ControlFlow})

target_include_directories(win32tools_bin PUBLIC "Include")
