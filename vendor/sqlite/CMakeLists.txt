cmake_minimum_required(VERSION 3.5)
project(SQLite VERSION 3)

set(${PROJECT_NAME}_implementation_files
        sqlite3.c
        sqlite3.h
        )

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_implementation_files})

set_property(TARGET ${PROJECT_NAME} PROPERTY LINKER_LANGUAGE C)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        )

