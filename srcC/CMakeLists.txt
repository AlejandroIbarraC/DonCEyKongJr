cmake_minimum_required(VERSION 3.14)
project(KeyDonCE C)

set(CMAKE_C_STANDARD 99)

add_executable(KeyDonCE main.c logic/CocodrileLogic.c logic/CocodrileLogic.h logic/CocodrileList.h logic/CocodrileList.c logic/FruitLogic.c logic/FruitLogic.h logic/FruitList.c logic/FruitList.h logic/DKLogic.c logic/DKLogic.h)