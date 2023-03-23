#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *ent;

    if (argc != 2)/*Check if there is an argument, assign current directory if not*/
    {
        dir = opendir(".");
    }else {
        dir = opendir(argv[1]);
    }

    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    } else {
        perror("not a valid directory to make ls");
        exit(1);
    }

    return 0;
}       