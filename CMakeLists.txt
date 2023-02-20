cmake_minimum_required(VERSION 3.2)
project(FireStone)

set(CMAKE_Application_STANDARD 23)

file(GLOB_RECURSE FireStone_Application_Sources "Application/*.cxx" "Application/*.hxx")
add_executable(FireStone ${FireStone_Application_Sources})

function(FireStone_Add_Internal_Library FolderName)
    file(GLOB_RECURSE FireStone_${FolderName}_Sources "${FolderName}/*.cxx" "${FolderName}/*.hxx")
    add_library(FireStone_${FolderName} ${FireStone_${FolderName}_Sources})
    target_include_directories(FireStone_${FolderName} PUBLIC ${FolderName})
    target_link_libraries(FireStone FireStone_${FolderName})

    message(STATUS "FireStone_${FolderName} added")
endfunction()

FireStone_Add_Internal_Library("DataTraffic")