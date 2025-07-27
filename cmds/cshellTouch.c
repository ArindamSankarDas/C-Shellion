#include <stdio.h>
#include <string.h>
#include "cmds.h"

int main(int argc, char *argv[]){
   if(argc < 2){
       printf("touch: need to provide argument for the command");
       return 1;
   }

   if (fileExists(argv[1]) == 0) {
       FILE *createFile = fopen(argv[1], "w");

       if(!createFile){
           printf("touch: error occured during the creation of the file");
           return 1;
       }

       fclose(createFile);
    }

   return 0;
}

int fileExists(char *filename){
    FILE *filePtr;

    if((filePtr = fopen(filename, "r")) != NULL){
       fclose(filePtr);

       printf("touch: File already exists");
       return 1;
    }

    return 0;
}
