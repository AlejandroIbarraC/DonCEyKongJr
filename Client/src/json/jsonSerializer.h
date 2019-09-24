#ifndef CLIENT_JSONSERIALIZER_H
#define CLIENT_JSONSERIALIZER_H

// Libraries
#include "../cjson/cJSON.h"
#include "../entity/Crocodile.h"
#include "../entity/Fruit.h"
#include <stdio.h>

#define ROWS 24
#define COLS 16

/**
 * @brief Function that receives an array and returns a json that contains it as an item
 * @param matrix : Matrix for parsing.
 * @return : Json parsed file.
 */
char* serialize_Matrix(int* matrix[ROWS][COLS]);

int parse_Matrix(const char *json);

/**
 * Function that indicates if the json enters corresponds to a crocodile
 * @param json: Incoming Data
 * @return : 1 if is an coco json or 0 if it is not
 */
int isCroc(const char *json);

/**
 * @brief Function that receives an json char* and returns an Kremlin instance
 * @param json : Incoming data Kremlin from server
 * @return : Kremlin instance ptr
 */
struct Crocodile deserialize_Croc(const char *json);

/**
 * Function that indicates if the json enters corresponds to a crocodile
 * @param json: Incoming Data
 * @return : 1 if is an coco json or 0 if it is not
 */
int isFruit(const char *json);

/**
 * @brief Function that receives an json char* and returns an Kremlin instance
 * @param json : Incoming data Kremlin from server
 * @return : Kremlin instance ptr
 */
struct Fruit deserialize_Fruit(const char *json);

#endif //CLIENT_JSONSERIALIZER_H
