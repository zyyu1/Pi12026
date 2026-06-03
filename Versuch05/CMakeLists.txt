cmake_minimum_required(VERSION 3.10)

project(Versuch05)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(V05
    main.cpp
    Liste.cpp
    ListenElement.cpp
    Student.cpp
)
