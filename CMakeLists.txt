cmake_minimum_required(VERSION 3.5)
project(b6b36pcc-semestral-work LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(core-files
        strongly-connected-components.cpp
        strongly-connected-components.hpp
        timer.hpp
)

add_executable(b6b36pcc-semestral-work
        main.cpp
        ${core-files}
)