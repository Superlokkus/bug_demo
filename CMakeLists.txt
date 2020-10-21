cmake_minimum_required(VERSION 3.0)
project(bug_demo VERSION 1.0)

find_package(Threads REQUIRED)

add_subdirectory(vendor/sqlite)


set(${PROJECT_NAME}_implementation_files
        main.cpp
        )


add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_implementation_files})
set_property(TARGET ${PROJECT_NAME} PROPERTY LINKER_LANGUAGE CXX)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)


target_link_libraries(${PROJECT_NAME}
        PRIVATE
        SQLite
        Threads::Threads
        ${CMAKE_DL_LIBS}
        )


target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/sqlite_modern_cpp/hdr
        )

install(TARGETS ${PROJECT_NAME}
        ARCHIVE
        DESTINATION lib)
install(TARGETS ${PROJECT_NAME}
        PUBLIC_HEADER
        DESTINATION include)

