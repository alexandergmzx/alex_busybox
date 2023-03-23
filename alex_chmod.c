#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <mode> <file>\n", argv[0]);
        return 1;
    }

    // Parse the mode argument
//    mode_t mode = strtol(argv[1], NULL, 8);
    char *mode_str = argv[1];
    int mode = strtol(mode_str, NULL, 8);

    // Change the mode of the file
    if (chmod(argv[2], mode) != 0) {
        perror("Error on chmod");
        return 1;
    }

    return 0;
}