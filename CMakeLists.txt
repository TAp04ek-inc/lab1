cmake_minimum_required(VERSION 3.10)

project(lab1)

set(SRC
    main.cpp
    file_io.cpp
    random_io.cpp
    console_io.cpp
    algorithm.cpp
    tests.cpp
)

add_executable(lab1-out ${SRC})