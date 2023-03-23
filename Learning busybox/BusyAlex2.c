#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main(int argc, char *argv[]) {
    char *cmd_name = strrchr(argv[0], '/') ? strrchr(argv[0], '/') + 1 : argv[0];

    if (strcmp(cmd_name, "sleep") == 0) {
        if (argc != 2) {
            fprintf(stderr, "Usage: %s seconds\n", cmd_name);
            exit(1);
        }
    printf("Executing sleep command...\n");
    execlp("sleep", "sleep", argv[1], (char *)NULL);
    perror("Error");
    exit(1);
    }

    if (strcmp(cmd_name, "ls") == 0) {
        if (argc == 1) {
            execlp("ls", "ls", (char *)NULL);
        } else if (argc == 2 && strcmp(argv[1], "-l") == 0) {
            execlp("ls", "ls", "-l", (char *)NULL);
        } else {
            fprintf(stderr, "Usage: %s [-l]\n", cmd_name);
            exit(1);
        }
    }

    fprintf(stderr, "Error: Command not found\n");
    exit(1);
}
