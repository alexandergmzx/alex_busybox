#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_INT 1024


void ls() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(".")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    } else {
        perror("");
        exit(EXIT_FAILURE);
    }
}

void sleep_cmd(int seconds) {
    sleep(seconds);
}

int main(int argc, char *argv[]) {
    pid_t pid;

    if (argc < 2) {
        fprintf(stderr, "Use: %s <pseudo-command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("Forking error");
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
        printf("Executing %s %s %s %s %s", "/bin/bash", "bash", "-c",command_ex, argv[2]);
        execl("/bin/bash", "bash", "-c",command_ex, argv[2], NULL);
        // We expect execl to end the execution of the child process, else is an error on execl execution
        perror("execl error");
        exit(EXIT_FAILURE);
    } else {
        // Parent process running
        int state_sig;
        waitpid(pid, &state_sig, 0);
        printf("/bin/bash bash -c %s %s %s",argv[1], argv[2]);
        if (WIFEXITED(state_sig)) {
            printf("Child process terminated with output code %d\n", WEXITSTATUS(state_sig));
        } else if (WIFSIGNALED(state_sig)) {
            printf("Child process terminated by the signal %d\n", WTERMSIG(state_sig));
        }
    }

    return 0;
}
