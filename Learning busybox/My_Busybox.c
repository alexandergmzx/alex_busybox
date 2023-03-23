#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* MY_SLEEP_PATH = "./my_sleep";
char* MY_LS_PATH = "./my_ls";

int main(int argc, char** argv) {
    if (strcmp(argv[0], "sleep") == 0) {
        execl(MY_SLEEP_PATH, MY_SLEEP_PATH, argv[1], NULL);
    } else if (strcmp(argv[0], "ls") == 0) {
        execl(MY_LS_PATH, MY_LS_PATH, argv[1], NULL);
    } else {
        fprintf(stderr, "Command not supported: %s\n", argv[0]);
        return 1;
    }
    return 0;
}