cmake_minimum_required(VERSION 3.17)
project(Who_is_Billy_here)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        sources/main.cpp
        sources/main_menu_button.cpp
        sources/main_menu.cpp
        sources/message.cpp
        )

set(HEADERS
        include/main_menu_button.h
        include/main_menu.h
        include/message.h
        )

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(Who_is_Billy_here ${SOURCES})

target_include_directories(Who_is_Billy_here
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Who_is_Billy_here sfml-graphics sfml-audio)