cmake_minimum_required(VERSION 3.17)
project(tema)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Weffc++")

add_executable(tema main.cpp headers/jucator.h sources/jucator.cpp headers/proprietate.h sources/proprietate.cpp headers/joc.h sources/joc.cpp headers/zar.h sources/zar.cpp headers/bani_actiune.h sources/bani_actiune.cpp headers/banca.h sources/banca.cpp)