cmake_minimum_required(VERSION 3.9)
project(app_name)

#
# General definitions
#
set(CMAKE_CXX_STANDARD 17)

# Shared includes
include_directories(include)
include_directories(3rd_parties/sciter-sdk/include)

# Cross compilation definitions

#
# Windows
#
if ( CMAKE_SYSTEM_NAME MATCHES "Windows" )
    set(WINDOW_MAIN_FILE 3rd_parties/sciter-sdk/include/sciter-win-main.cpp)
    execute_process(COMMAND 3rd_parties\\sciter-sdk\\bin.win\\packfolder.exe src\\web "include\\resources.h" -v "resources"
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
endif ()

#
# Linux
#
if ( CMAKE_SYSTEM_NAME MATCHES "Linux" )
    set(WINDOW_MAIN_FILE 3rd_parties/sciter-sdk/include/sciter-gtk-main.cpp)
    execute_process(COMMAND 3rd_parties/sciter-sdk/bin.lnx/packfolder src/web include/resources.h -v "resources"
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
endif ()

#
# macOS
#
if ( CMAKE_SYSTEM_NAME MATCHES "Darwin" )
    set(WINDOW_MAIN_FILE 3rd_parties/sciter-sdk/include/sciter-osx-main.mm)
    execute_process(COMMAND 3rd_parties/sciter-sdk/bin.osx/packfolder src/web include/resources.h -v "resources"
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
endif ()

#
# Shared library build definitions
#
set(SOURCE_FILES ${WINDOW_MAIN_FILE})
