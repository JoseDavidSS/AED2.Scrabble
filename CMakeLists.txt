cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 14)

add_executable(Scrabble src/tec/ac/cr/Scrabble/main.cpp src/tec/ac/cr/Scrabble/Server/Client.cpp src/tec/ac/cr/Scrabble/Server/Client.h src/tec/ac/cr/Scrabble/Logic/Lists/Node.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Node.h)