#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src/logic/data/codes.h"
#include "src/sockets/clientSocket.h"
#include "src/ui/donkeyUI.h"

int readCSV(int* matrix[24][16]){
    char buffer[1024] ;
    char path[1000] = "..\\src\\logic\\data\\matrix.csv";
    char *record,*line;
    int i=0,j=0;
    FILE *fstream;
    fstream = fopen(path,"r");
    if(fstream == NULL)
    {
        perror("\n file opening failed ");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<24;i++){
        line=fgets(buffer,sizeof(buffer),fstream);
        record = strtok(line,",");
        const char *rec = record;
        for(j=0;j<16;j++){
            const char *s = record;
            int val;
            sscanf(s,"%d",&val);
            printf("[%d]",val);
            matrix[i][j] = (int*)val;
            record = strtok(NULL, ",");
        }
        printf("\n");

    }
    fclose(fstream);


    return 0 ;
}

int main(int argc, char *argv[]){

    char *json1 = "{\"iD\":1,\"iPos\":234,\"jPos\":567,\"onScreen\":1,\"onField\":99,\"onVine\":0,\"crocSpeed\":22,\"mouth\":2,\"whichCroc\":null,\"viewU\":90,\"viewD\":8,\"viewR\":56,\"viewL\":12}";
    /*if(isCoco(json1)){
        struct crocodrile k = deserialize_Coco(json1);
        printCoco(k);
    }else {
        struct fruit f = deserialize_Fruit(json1);
        printFruit(f);
    }*/

    //init_Donkey(argc,argv);
    int* mat[24][16];
    readCSV(mat);
    printf("%d",mat[22][0] == (int*)dkjr_WR1);
    return 0;
}