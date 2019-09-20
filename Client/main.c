#include <stdio.h>
#include "src/json/jsonSerializer.h"

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

void printKremlin(struct Kremlin k){
    printf("KREMLIN \n*%d \n*%d \n*%d \n*%d \n*%d \n*%d \n*%d \n*%d",k.id,k.posI,k.posJ,k.onScreen,k.cocoSpeed,k.inVine,k.onField,k.wishCoco);
}

int main(){
    char *json = "  {\n"
                 "        \"id\":1,\n"
                 "        \"posI\":2,\n"
                 "        \"posJ\":3,\n"
                 "        \"onScreen\":4,\n"
                 "        \"cocoSpeed\":5,\n"
                 "        \"inVine\":6,\n"
                 "        \"onField\":7,\n"
                 "        \"wishCoco\":8\n"
                 "    }";

    struct Kremlin k = deserialize_Kremlin(json);
    printKremlin(k);
    return 0;
}