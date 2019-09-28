

#ifndef DONCEYKONGJR_SERIALIZER_H
#define DONCEYKONGJR_SERIALIZER_H

// Libraries
#include "cJson.h"
#include "../logic/entity/Crocodile.h"
#include "../logic/entity/Fruit.h"
#include <stdio.h>

char* serializeMatrix(int matrix[24][16]);
int isKremlin(const char* json);
struct Crocodile* deserializeKremlin(const char *json);
int isFruit(const char* json);
struct Fruit* deserializeFruit(const char *json);

#endif //DONCEYKONGJR_SERIALIZER_H
