cmake_minimum_required(VERSION 3.13)
project(Client)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
link_libraries(ws2_32 wsock32)
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

add_executable(Client main.c
                src/sockets/clientSocket.h
                src/sockets/clientSocket.c

                src/json/jsonSerializer.h
                src/json/jsonSerializer.c

                src/ui/donkeyUI.c
                src/ui/donkeyUI.h

                src/cjson/cJSON.h
                src/cjson/cJSON.c

                src/entity/CrocodrileList.h
                src/entity/CrocodrileList.c
                src/entity/CrocodrileLogic.h
                src/entity/CrocodrileLogic.c

                src/entity/DKLogic.h
                src/entity/DKLogic.c

                src/entity/FruitList.h
                src/entity/FruitList.c
                src/entity/FruitLogic.h
                src/entity/FruitLogic.c
                src/entity/game.c src/entity/game.h)

TARGET_LINK_LIBRARIES(Client ${GTK3_LIBRARIES} -lmingw32 -lws2_32 -lwsock32 -lmswsock -lallegro-5.0.10-monolith-md-debug)