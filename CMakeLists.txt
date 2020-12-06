cmake_minimum_required(VERSION 3.17)
project(tema)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Weffc++")

add_executable(tema main.cpp headers/jucator.h sources/jucator.cpp headers/spatiu_proprietate.h sources/spatiu_proprietate.cpp headers/joc.h sources/joc.cpp headers/zar.h sources/zar.cpp headers/bani_actiune.h sources/bani_actiune.cpp headers/banca.h sources/banca.cpp headers/spatiu_joc.h sources/spatiu_joc.cpp headers/alt_spatiu.h sources/alt_spatiu.cpp)