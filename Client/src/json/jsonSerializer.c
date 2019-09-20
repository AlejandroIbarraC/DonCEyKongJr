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


int isCoco(const char *json){
    cJSON *coco_Json = cJSON_Parse(json);
    if (coco_Json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        goto end;
    }


    cJSON *id = cJSON_GetObjectItemCaseSensitive(coco_Json,"iD");
    if(cJSON_IsNumber(id)){
        return (id->valueint == 1);
    }

    end:
    cJSON_Delete(coco_Json);
    return 0;
}

// if iD equals 2 then is a fruit
int isFruit(const char *json){
    cJSON *fruit_Json = cJSON_Parse(json);
    if (fruit_Json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        goto end;
    }


    cJSON *id = cJSON_GetObjectItemCaseSensitive(fruit_Json,"iD");
    if(cJSON_IsNumber(id)){
        return (id->valueint == 2);
    }

    end:
    cJSON_Delete(fruit_Json);
    return 0;
}

/*
 *  cocodrile JSON format: [iD code: 1]
 *
    {
        "iD":1,
        "iPos":2,
        "jPos":3,
        "onScreen":4,
        "cocoSpeed":5,
        "onVine":6,
        "onField":7,
        "whichCoco":8,
        "mouth":9,
        "viewU":10,
        "viewD":11,
        "viewR":12,
        "viewL":13
    }
 */
struct cocodrile deserialize_Coco(const char *json){
    struct cocodrile _coco = { .iD = 0};
    // cJSON data tokens
    cJSON *iD,  *posI, *posJ;
    cJSON *onScreen, *onField;
    cJSON *cocoSpeed, *inVine,  *whichCoco;
    cJSON *mouth;
    cJSON *viewR, *viewL,*viewU, *viewD;

    cJSON *coco_Json = cJSON_Parse(json);
    if (coco_Json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        goto end;
    }


    iD = cJSON_GetObjectItemCaseSensitive(coco_Json,"iD");
    if(cJSON_IsNumber(iD)){
        _coco.iD = iD->valueint;
    }

    posI = cJSON_GetObjectItemCaseSensitive(coco_Json,"iPos");
    if(cJSON_IsNumber(posI)){
        _coco.iPos = posI->valueint;
    }

    posJ = cJSON_GetObjectItemCaseSensitive(coco_Json,"jPos");
    if(cJSON_IsNumber(posJ)){
        _coco.jPos = posJ->valueint;
    }

    onScreen = cJSON_GetObjectItemCaseSensitive(coco_Json,"onScreen");
    if(cJSON_IsNumber(onScreen)){
        _coco.onScreen = onScreen->valueint;
    }

    cocoSpeed = cJSON_GetObjectItemCaseSensitive(coco_Json,"cocoSpeed");
    if(cJSON_IsNumber(cocoSpeed)){
        _coco.cocoSpeed = cocoSpeed->valueint;
    }

    inVine = cJSON_GetObjectItemCaseSensitive(coco_Json,"onVine");
    if(cJSON_IsNumber(inVine)){
        _coco.onVine = inVine->valueint;
    }

    onField = cJSON_GetObjectItemCaseSensitive(coco_Json,"onField");
    if(cJSON_IsNumber(onField)){
        _coco.onField = onField->valueint;
    }

    whichCoco = cJSON_GetObjectItemCaseSensitive(coco_Json,"whichCoco");
    if(cJSON_IsNumber(whichCoco)){
        _coco.whichCoco = whichCoco->valueint;
    }

    mouth = cJSON_GetObjectItemCaseSensitive(coco_Json,"mouth");
    if(cJSON_IsNumber(mouth)){
        _coco.mouth = mouth->valueint;
    }

    viewU = cJSON_GetObjectItemCaseSensitive(coco_Json,"viewU");
    if(cJSON_IsNumber(viewU)){
        _coco.viewU = viewU->valueint;
    }

    viewD = cJSON_GetObjectItemCaseSensitive(coco_Json,"viewD");
    if(cJSON_IsNumber(viewD)){
        _coco.viewD = viewD->valueint;
    }

    viewR = cJSON_GetObjectItemCaseSensitive(coco_Json,"viewR");
    if(cJSON_IsNumber(viewR)){
        _coco.viewR = viewR->valueint;
    }

    viewL = cJSON_GetObjectItemCaseSensitive(coco_Json,"viewL");
    if(cJSON_IsNumber(viewL)){
        _coco.viewL = viewL->valueint;
    }

    end:
    cJSON_Delete(coco_Json);
    return _coco;
}

/*
 *  cocodrile JSON format: [iD code: 1]
 *
    {
        "iD":0,
        "iPos":2,
        "jPos":3,
        "onScreen":4,
        "onVine":6,
        "onField":7,
        "whichFruit":8
    }
 */
struct fruit deserialize_Fruit(const char *json){
    struct fruit _fruit = { .iD = 0};
    // cJSON data tokens
    cJSON *iD,  *posI, *posJ;
    cJSON *onScreen, *onField, *inVine,  *whichFruit;

    cJSON *fruit_Json = cJSON_Parse(json);
    if (fruit_Json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        goto end;
    }


    iD = cJSON_GetObjectItemCaseSensitive(fruit_Json,"iD");
    if(cJSON_IsNumber(iD)){
        _fruit.iD = iD->valueint;
    }

    posI = cJSON_GetObjectItemCaseSensitive(fruit_Json,"iPos");
    if(cJSON_IsNumber(posI)){
        _fruit.iPos = posI->valueint;
    }

    posJ = cJSON_GetObjectItemCaseSensitive(fruit_Json,"jPos");
    if(cJSON_IsNumber(posJ)){
        _fruit.jPos = posJ->valueint;
    }

    onScreen = cJSON_GetObjectItemCaseSensitive(fruit_Json,"onScreen");
    if(cJSON_IsNumber(onScreen)){
        _fruit.onScreen = onScreen->valueint;
    }

    inVine = cJSON_GetObjectItemCaseSensitive(fruit_Json,"onVine");
    if(cJSON_IsNumber(inVine)){
        _fruit.onVine = inVine->valueint;
    }

    onField = cJSON_GetObjectItemCaseSensitive(fruit_Json,"onField");
    if(cJSON_IsNumber(onField)){
        _fruit.onField = onField->valueint;
    }

    whichFruit = cJSON_GetObjectItemCaseSensitive(fruit_Json,"whichFruit");
    if(cJSON_IsNumber(whichFruit)){
        _fruit.whichFruit = whichFruit->valueint;
    }

    end:
    cJSON_Delete(fruit_Json);
    return _fruit;
}