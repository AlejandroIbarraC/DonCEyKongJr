#include <stdio.h>
#include "src/json/jsonSerializer.h"
#include "src/sockets/clientSocket.h"
#include "src/ui/donkeyUI.h"

/*int main(){
    int matrix[24][16] = { {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9},
                       {7, 1, 8, 4, 3, 5, 9, 4, 7, 4, 0, 2, 1, 5, 0, 9}};

    printf("%s", serialize_Matrix(matrix));
}*/

int supports_full_hd(const char * const monitor)
{
    const cJSON *resolution = NULL;
    const cJSON *resolutions = NULL;
    const cJSON *name = NULL;
    int status = 0;
    cJSON *monitor_json = cJSON_Parse(monitor);
    if (monitor_json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        status = 0;
        goto end;
    }

    name = cJSON_GetObjectItemCaseSensitive(monitor_json, "name");
    if (cJSON_IsString(name) && (name->valuestring != NULL))
    {
        printf("Checking monitor \"%s\"\n", name->valuestring);
    }

    resolutions = cJSON_GetObjectItemCaseSensitive(monitor_json, "resolutions");
    cJSON_ArrayForEach(resolution, resolutions)
    {
        cJSON *width = cJSON_GetObjectItemCaseSensitive(resolution, "width");
        cJSON *height = cJSON_GetObjectItemCaseSensitive(resolution, "height");

        if (!cJSON_IsNumber(width) || !cJSON_IsNumber(height))
        {
            status = 0;
            goto end;
        }

        if ((width->valuedouble == 1920) && (height->valuedouble == 1080))
        {
            status = 1;
            goto end;
        }
    }

    end:
    cJSON_Delete(monitor_json);
    printf("status: %d",status);
    return status;
}

void printCoco(struct crocodrile k){
    printf("CROCODRILE \n*iD: %d \n*iPos:%d \n*jPos:%d \n*%d \n*%d \n*%d \n*%d \n*%d\n*%d\n",k.iD,k.iPos,k.jPos,k.onScreen,k.crocSpeed,k.onVine,k.onField,k.whichCroc,k.mouth);
}

void printFruit(struct fruit f){
    printf("FRUIT \n*%d \n*%d \n*%d \n*%d \n*%d \n*%d \n*%d \n",f.iD,f.iPos,f.jPos,f.onScreen,f.onVine,f.onField,f.whichFruit);
}

int main(int argc, char *argv[]){

    char *json1 = "{\"iD\":1,\"iPos\":234,\"jPos\":567,\"onScreen\":1,\"onField\":99,\"onVine\":0,\"crocSpeed\":22,\"mouth\":2,\"whichCroc\":null,\"viewU\":90,\"viewD\":8,\"viewR\":56,\"viewL\":12}";
    if(isCoco(json1)){
        struct crocodrile k = deserialize_Coco(json1);
        printCoco(k);
    }else {
        struct fruit f = deserialize_Fruit(json1);
        printFruit(f);
    }

    init_Donkey(argc,argv);

    return 0;
}