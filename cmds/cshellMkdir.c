#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
   if(argc < 2){
       printf("cshellMkdir: need to provide argument for the command\n");
       return 1;
   }

   int result = mkdir(argv[1], 0755);

   if (result == 0) {
       printf("Directory %s successfully created\n", argv[1]);
   }else{
      if(errno == EEXIST){
          printf("Directory %s already exists\n", argv[1]);
      }else{
          perror("Error occured while creating a directory\n");
      }
      return 1;
   }

   return 0;
}
