cmake_minimum_required(VERSION 3.13)
project(Client)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
link_libraries(ws2_32 wsock32)
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

add_executable(Client src/ui/main.c
                src/sockets/clientSocket.h
                src/sockets/clientSocket.c

                #src/json/jsonSerializer.h
                #src/json/jsonSerializer.c

                src/ui/donkeyUI.c
                src/ui/donkeyUI.h

                src/cjson/cJSON.h
                src/cjson/cJSON.c

        src/logic/data/codes.h src/entity/Crocodile.h src/entity/Fruit.h src/entity/DKJr.h src/logic/entityList/FruitList.c src/logic/entityList/FruitList.h src/logic/entityList/CrocList.c src/logic/entityList/CrocList.h src/logic/game/Game.c src/logic/game/Game.h src/logic/game/DonkeyDynamics.c src/logic/game/DonkeyDynamics.h src/ui/GameUI.c src/ui/GameUI.h)

TARGET_LINK_LIBRARIES(Client ${GTK3_LIBRARIES} -lmingw32 -lws2_32 -lwsock32 -lmswsock -lallegro-5.0.10-monolith-md-debug)