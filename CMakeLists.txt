cmake_minimum_required(VERSION 3.2)
project(FireStone)

set(CMAKE_Application_STANDARD 23)
enable_testing()

file(GLOB_RECURSE FireStone_Application_Sources "Application/*.cxx" "Application/*.hxx")
add_executable(FireStone ${FireStone_Application_Sources})

function(FireStone_Add_Internal_Library FolderName)
    file(GLOB_RECURSE FireStone_${FolderName}_Sources "${FolderName}/*.cxx" "${FolderName}/*.hxx")
    add_library(FireStone_${FolderName} ${FireStone_${FolderName}_Sources})
    target_link_libraries(FireStone FireStone_${FolderName})
    target_include_directories(FireStone_${FolderName} PUBLIC "Include")

    # Add tests, [Test/<FolderName>/<TestName>/] inside will be CXX and HXX files. There will be a Test.cxx file in each test directory.
    file(GLOB_RECURSE FireStone_${FolderName}_Test_Sources "Test/${FolderName}/*/*.cxx" "Test/${FolderName}/*/*.hxx")
    foreach(FireStone_${FolderName}_Test_Source ${FireStone_${FolderName}_Test_Sources})
        get_filename_component(FireStone_${FolderName}_Test_Name ${FireStone_${FolderName}_Test_Source} NAME_WE)
        get_filename_component(FireStone_${FolderName}_Test_Path ${FireStone_${FolderName}_Test_Source} PATH)
        add_executable(FireStone_${FolderName}_${FireStone_${FolderName}_Test_Name} ${FireStone_${FolderName}_Test_Source})
        target_link_libraries(FireStone_${FolderName}_${FireStone_${FolderName}_Test_Name} FireStone_${FolderName})
        target_include_directories(FireStone_${FolderName}_${FireStone_${FolderName}_Test_Name} PUBLIC "Include")
        add_test(NAME FireStone_${FolderName}_${FireStone_${FolderName}_Test_Name} COMMAND FireStone_${FolderName}_${FireStone_${FolderName}_Test_Name})
    endforeach()

    # Auto generate an include file, [Include/FireStone/<LibraryName>] will automatically have all HXX paths in it.
    file(GLOB_RECURSE FireStone_${FolderName}_Include_Sources "${FolderName}/*.hxx")
    file(WRITE "Include/FireStone/${FolderName}" "#pragma once\n")
    foreach(FireStone_${FolderName}_Include_Source ${FireStone_${FolderName}_Include_Sources})
        # Relative path from the include file to the actual HXX file.
        file(RELATIVE_PATH FireStone_${FolderName}_Include_Relative_Path "${CMAKE_CURRENT_SOURCE_DIR}/Include/FireStone/${FolderName}" "${FireStone_${FolderName}_Include_Source}")
        file(APPEND "Include/FireStone/${FolderName}" "\n#include \"${FireStone_${FolderName}_Include_Relative_Path}\"")
    endforeach()

    # Set the C++ version explicitly to C++23.
    set_property(TARGET FireStone_${FolderName} PROPERTY CXX_STANDARD 23)
    set_property(TARGET FireStone_${FolderName} PROPERTY CXX_STANDARD_REQUIRED ON)
    set_property(TARGET FireStone_${FolderName} PROPERTY CXX_EXTENSIONS OFF)

    message(STATUS "FireStone_${FolderName} added")
endfunction()

FireStone_Add_Internal_Library("DataTraffic")

include_directories("Include")
target_include_directories(FireStone PUBLIC "Include")