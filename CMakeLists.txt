cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(Scrabble src/tec/ac/cr/Scrabble/main.cpp src/tec/ac/cr/Scrabble/Server/Client.cpp src/tec/ac/cr/Scrabble/Server/Client.h src/tec/ac/cr/Scrabble/Server/ASync.cpp src/tec/ac/cr/Scrabble/Server/ASync.h src/tec/ac/cr/Scrabble/Logic/Data/Holder.cpp src/tec/ac/cr/Scrabble/Logic/Data/Holder.h src/tec/ac/cr/Scrabble/Logic/Lists/Matrix/Node.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Matrix/Node.h src/tec/ac/cr/Scrabble/Logic/Lists/Matrix/List.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Matrix/List.h src/tec/ac/cr/Scrabble/Logic/Lists/Matrix/Matrix.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Matrix/Matrix.h src/tec/ac/cr/Scrabble/Logic/Lists/Letters/LetterList.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Letters/LetterList.h src/tec/ac/cr/Scrabble/Logic/Lists/Letters/LetterNode.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Letters/LetterNode.h src/tec/ac/cr/Scrabble/Logic/Lists/Dictionary/Btree.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Dictionary/Btree.h src/tec/ac/cr/Scrabble/UI/menu.cpp src/tec/ac/cr/Scrabble/UI/menu.h src/tec/ac/cr/Scrabble/UI/menu.ui src/tec/ac/cr/Scrabble/Logic/Lists/Dictionary/WordList.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Dictionary/WordList.h src/tec/ac/cr/Scrabble/Logic/Lists/Dictionary/WordNode.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Dictionary/WordNode.h src/tec/ac/cr/Scrabble/Logic/Lists/Matrix/LastPlayList.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Matrix/LastPlayList.h src/tec/ac/cr/Scrabble/Logic/Lists/Matrix/LastPlayNode.cpp src/tec/ac/cr/Scrabble/Logic/Lists/Matrix/LastPlayNode.h src/tec/ac/cr/Scrabble/UI/assets/resources.qrc src/tec/ac/cr/Scrabble/UI/connectwindow.cpp src/tec/ac/cr/Scrabble/UI/connectwindow.h src/tec/ac/cr/Scrabble/UI/connectwindow.ui src/tec/ac/cr/Scrabble/UI/board.cpp src/tec/ac/cr/Scrabble/UI/board.h src/tec/ac/cr/Scrabble/UI/board.ui src/tec/ac/cr/Scrabble/UI/assets/letters)

target_link_libraries(Scrabble Qt5::Core Qt5::Gui Qt5::Widgets)
