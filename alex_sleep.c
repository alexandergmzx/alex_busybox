#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check if the user provided a valid number of seconds
    int seconds;
    if (argc < 2 || sscanf(argv[1], "%d", &seconds) != 1 || seconds < 0) {
        fprintf(stderr, "Error: Please provide a valid number of seconds. %s not supported.\n",argv[1]);
        fprintf(stderr, "Usage: alex_sleep <seconds>\n");
        exit(1);
    }
    // Sleep for the specified number of seconds
    sleep(seconds);
    printf("slept %d seconds :)\n",seconds);
    return 0;
}
