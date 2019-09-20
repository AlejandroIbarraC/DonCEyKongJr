#include "jsonSerializer.h"

// Function that receives an array and returns a json that contains it as an item
char* serialize_Matrix(int matrix[ROWS][COLS]){


    char *json_File;

    cJSON *_row = cJSON_CreateArray();

    cJSON *json_Object = cJSON_CreateObject();
    if(json_Object == NULL)
        goto end;

    cJSON *_matrix = cJSON_CreateArray();
    if(_matrix == NULL)
        goto end;

    // This variable creates cJSON objects to be able to enter them into the Array
    cJSON *_item;

    for(int i = 0; i < ROWS; i++) {

        _row = cJSON_CreateArray();
        for (int j = 0; j < COLS; j++) {
            _item = cJSON_CreateNumber(matrix[i][j]);
            cJSON_AddItemToArray(_row, _item);
        }

        cJSON_AddItemToArray(_matrix,_row);
    }

    cJSON_AddItemToObject(json_Object,"objMatrix",_matrix);

    json_File = cJSON_Print(json_Object);
    if (json_File == NULL)
    {
        fprintf(stderr, "Failed to print monitor.\n");
    }

    end:
    cJSON_Delete(json_Object);
    return json_File;
}


/*
 *  Kremlin JSON format:
 *
    {
        "id":1,
        "posI":2,
        "posJ":3,
        "onScreen":4,
        "cocoSpeed":5,
        "inVine":6,
        "onField":7,
        "wishCoco":8
    }
 */
struct Kremlin deserialize_Kremlin(const char *json){
    struct Kremlin kremlin = { .id = 0, .posI= 0, .posJ = 0, .onScreen= 0, .cocoSpeed= 0, .inVine= 0, .onField= 0, .wishCoco= 0};
    // cJSON data tokens
    cJSON *id;
    cJSON *posI;
    cJSON *posJ;
    cJSON *onScreen;
    cJSON *cocoSpeed;
    cJSON *inVine;
    cJSON *onField;
    cJSON *wishCoco;

    cJSON *kremlin_Json = cJSON_Parse(json);
    if (kremlin_Json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        goto end;
    }


    id = cJSON_GetObjectItemCaseSensitive(kremlin_Json,"id");
    if(cJSON_IsNumber(id)){
        kremlin.id = id->valueint;
    }

    posI = cJSON_GetObjectItemCaseSensitive(kremlin_Json,"posI");
    if(cJSON_IsNumber(posI)){
        kremlin.posI = posI->valueint;
    }

    posJ = cJSON_GetObjectItemCaseSensitive(kremlin_Json,"posJ");
    if(cJSON_IsNumber(posJ)){
        kremlin.posJ = posJ->valueint;
    }

    onScreen = cJSON_GetObjectItemCaseSensitive(kremlin_Json,"onScreen");
    if(cJSON_IsNumber(onScreen)){
        kremlin.onScreen = onScreen->valueint;
    }

    cocoSpeed = cJSON_GetObjectItemCaseSensitive(kremlin_Json,"cocoSpeed");
    if(cJSON_IsNumber(cocoSpeed)){
        kremlin.cocoSpeed = cocoSpeed->valueint;
    }

    inVine = cJSON_GetObjectItemCaseSensitive(kremlin_Json,"inVine");
    if(cJSON_IsNumber(inVine)){
        kremlin.inVine = inVine->valueint;
    }

    onField = cJSON_GetObjectItemCaseSensitive(kremlin_Json,"onField");
    if(cJSON_IsNumber(onField)){
        kremlin.onField = onField->valueint;
    }

    wishCoco = cJSON_GetObjectItemCaseSensitive(kremlin_Json,"wishCoco");
    if(cJSON_IsNumber(wishCoco)){
        kremlin.wishCoco = wishCoco->valueint;
    }

    end:
    return kremlin;
}
