cmake_minimum_required(VERSION 3.13)
project(Client)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client main.c
                src/sockets/clientSocket.h
                src/sockets/clientSocket.c

                src/json/jsonSerializer.h
                src/json/jsonSerializer.c

                src/ui/donkeyUI.c
                src/ui/donkeyUI.h

                src/cjson/cJSON.h
                src/cjson/cJSON.c

                src/entity/CocodrileList.h
                src/entity/CocodrileList.c
                src/entity/CocodrileLogic.h
                src/entity/CocodrileLogic.c

                src/entity/DKLogic.h
                src/entity/DKLogic.c

                src/entity/FruitList.h
                src/entity/FruitList.c
                src/entity/FruitLogic.h
                src/entity/FruitLogic.c
        )

