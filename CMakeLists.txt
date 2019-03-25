cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(Scrabble src/tec/ac/cr/Scrabble/main.cpp src/tec/ac/cr/Scrabble/Server/Client.cpp src/tec/ac/cr/Scrabble/Server/Client.h src/tec/ac/cr/Scrabble/Logic/ASync.cpp src/tec/ac/cr/Scrabble/Logic/ASync.h src/tec/ac/cr/Scrabble/Logic/Data/Holder.cpp src/tec/ac/cr/Scrabble/Logic/Data/Holder.h src/tec/ac/cr/Scrabble/Logic/Lists/Node.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Node.h src/tec/ac/cr/Scrabble/Logic/Lists/List.cpp src/tec/ac/cr/Scrabble/Logic/Lists/List.h src/tec/ac/cr/Scrabble/Logic/Lists/Matrix.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Matrix.h src/tec/ac/cr/Scrabble/Logic/Player.cpp src/tec/ac/cr/Scrabble/Logic/Player.h src/tec/ac/cr/Scrabble/Logic/Lists/LetterList.cpp src/tec/ac/cr/Scrabble/Logic/Lists/LetterList.h src/tec/ac/cr/Scrabble/Logic/Lists/LetterNode.cpp src/tec/ac/cr/Scrabble/Logic/Lists/LetterNode.h src/tec/ac/cr/Scrabble/Logic/Lists/Btree.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Btree.h src/tec/ac/cr/Scrabble/UI/menu.cpp src/tec/ac/cr/Scrabble/UI/menu.h src/tec/ac/cr/Scrabble/UI/menu.ui)

target_link_libraries(Scrabble Qt5::Core Qt5::Gui Qt5::Widgets)
