cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Scrabble src/tec/ac/cr/Scrabble/Logic/Lists/main.cpp src/tec/ac/cr/Scrabble/Server/Client.cpp src/tec/ac/cr/Scrabble/Server/Client.h src/tec/ac/cr/Scrabble/Logic/ASync.cpp src/tec/ac/cr/Scrabble/Logic/ASync.h src/tec/ac/cr/Scrabble/Logic/Data/Holder.cpp src/tec/ac/cr/Scrabble/Logic/Data/Holder.h src/tec/ac/cr/Scrabble/Logic/Lists/Node.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Node.h src/tec/ac/cr/Scrabble/Logic/Lists/List.cpp src/tec/ac/cr/Scrabble/Logic/Lists/List.h src/tec/ac/cr/Scrabble/Logic/Lists/Matrix.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Matrix.h src/tec/ac/cr/Scrabble/Logic/Player.cpp src/tec/ac/cr/Scrabble/Logic/Player.h src/tec/ac/cr/Scrabble/Logic/Lists/LetterList.cpp src/tec/ac/cr/Scrabble/Logic/Lists/LetterList.h src/tec/ac/cr/Scrabble/Logic/Lists/LetterNode.cpp src/tec/ac/cr/Scrabble/Logic/Lists/LetterNode.h src/tec/ac/cr/Scrabble/Logic/Lists/Btree.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Btree.h)