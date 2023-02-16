cmake_minimum_required(VERSION 3.2)
project(Rayonix_Win32Tools)

set(CMAKE_CXX_STANDARD 20)

# Add control flow library
file(GLOB_RECURSE Rayonix_Win32Tools_ControlFlow_Files "ControlFlow/*.cxx" "ControlFlow/*.hxx" "ControlFlow/*.c" "ControlFlow/*.h")
add_library(Rayonix_Win32Tools_ControlFlow ${Rayonix_Win32Tools_ControlFlow_Files})

# Add entry program
file(GLOB_RECURSE Rayonix_Win32Tools_Entry_Files "Entry/*.cxx" "Entry/*.hxx" "Entry/*.c" "Entry/*.h")
add_executable(win32tools_bin ${Rayonix_Win32Tools_Entry_Files})

# Link control flow library
target_link_libraries(win32tools_bin Rayonix_Win32Tools_ControlFlow)

# Add include directories
target_include_directories(Rayonix_Win32Tools_ControlFlow PUBLIC "Include")
target_include_directories(win32tools_bin PUBLIC "Include")

# Set C++ version
set_target_properties(Rayonix_Win32Tools_ControlFlow PROPERTIES CXX_STANDARD 20)
set_target_properties(win32tools_bin PROPERTIES CXX_STANDARD 20)
