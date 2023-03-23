#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int seconds;
    char input[100];

    if (argc < 2) {
        fprintf(stderr, "Error: Please provide the number of seconds as an argument.\n %s not supported.\n",argv[1]);
        fprintf(stderr, "Usage: mysleep <seconds>\n");
        exit(1);
    }

    // Combine all the arguments into a single string
    input[0] = '\0';
    for (int i = 1; i < argc; i++) {
        strcat(input, argv[i]);
    }

    // Check if the user provided a valid number of seconds
    if (sscanf(input, "%d", &seconds) != 1 || seconds < 0) {
        fprintf(stderr, "Error: Please provide a valid number of seconds.\n");
        fprintf(stderr, "Usage: mysleep <seconds>\n");
        exit(1);
    }

    // Sleep for the specified number of seconds
    sleep(seconds);

    return 0;
}
