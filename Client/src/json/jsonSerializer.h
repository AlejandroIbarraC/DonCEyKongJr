#ifndef CLIENT_JSONSERIALIZER_H
#define CLIENT_JSONSERIALIZER_H

// Libraries
#include "../cjson/cJSON.h"
#include <stdio.h>

#define ROWS 24
#define COLS 16

/**
 * @brief Function that receives an array and returns a json that contains it as an item
 * @param matrix : Matrix for parsing.
 * @return : Json parsed file.
 */
char* serialize_Matrix(int matrix[ROWS][COLS]);


#endif //CLIENT_JSONSERIALIZER_H
