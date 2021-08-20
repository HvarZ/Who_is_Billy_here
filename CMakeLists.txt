cmake_minimum_required(VERSION 3.17)
project(Who_is_Billy_here)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        sources/main.cpp
        )

set(HEADERS
        )

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(Who_is_Billy_here ${SOURCES})

target_include_directories(Who_is_Billy_here
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Who_is_Billy_here sfml-graphics sfml-audio)