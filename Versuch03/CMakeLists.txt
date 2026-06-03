cmake_minimum_required(VERSION 3.10)

project(Versuch03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(V03
    othello.cpp
    othelloKI.cpp
    test.cpp
)
