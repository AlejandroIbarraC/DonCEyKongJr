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
