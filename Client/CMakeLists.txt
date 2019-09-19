cmake_minimum_required(VERSION 3.13)
project(Client)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client main.c src/sockets/clientSocket.h
                src/sockets/clientSocket.c
                src/json/jsonSerializer.h
                src/json/jsonSerializer.c
                src/ui/donkeyUI.c
                src/ui/donkeyUI.h
                src/cjson/cJSON.h
                src/cjson/cJSON.c)

