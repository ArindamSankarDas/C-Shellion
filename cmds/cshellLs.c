#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]){
    if(argc > 1){
       printf("can't have more than 1 argument");
       return 1;
    }

    if(argv[1] != NULL){
        printf("This version of custom \"ls\" doesn't take any arguments\n");
        return 1;
    }

    DIR *dir;

    struct dirent *entry;

    dir = opendir(".");

    if(dir == NULL){
        perror("Error opening the directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
