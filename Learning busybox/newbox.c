#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Check if this is the child process
        char *command_ex = NULL;

        if (strcmp(argv[1], "fecha") == 0) {
            command_ex = "date";
        } else if (strcmp(argv[1], "quiensoy") == 0) {
            command_ex = "whoami";
        } else if (strcmp(argv[1], "tiempo") == 0) {
            command_ex = "uptime -p";
        } else if (strcmp(argv[1], "sleep") == 0) {
            command_ex = "./alex_sleep";
        } else {
            fprintf(stderr, "Unknown command: %s, %s\n", argv[1], argv[2]);
            exit(EXIT_FAILURE);
        }
        char *args[] = {command_ex, argv[2], NULL}; // Specify the command and arguments to be executed

        execvp(args[0], args); // Execute the command with arguments

        // If execvp returns, an error has occurred
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // This is the parent process
        // Wait for the child process to finish
        waitpid(pid, &status, 0);

        // Check if the child process exited normally
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process terminated abnormally\n");
        }
    }

    return 0;
}