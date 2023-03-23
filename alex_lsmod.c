#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_MODULES 256

int main() {
    // Open the /proc/modules file for reading
    FILE *file = fopen("/proc/modules", "r");

    // Handle errors opening the file
    if (file == NULL) {
        perror("Error opening /proc/modules");
        return 1;
    }

    // Read each line in the file and print the module name and size
    char line[MAX_LINE_LENGTH];
    int count = 0;

    printf("Module               Size     Used by\n");
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && count < MAX_MODULES) {
        // Parse the module name and size from the line
        char name[MAX_LINE_LENGTH], size[MAX_LINE_LENGTH], user[MAX_LINE_LENGTH], user_module[MAX_LINE_LENGTH];
        sscanf(line, "%s %s %s %s", name, size, user, user_module);

        // Print the module name and size
        printf("%-20s %-8s %-5s %s\n", name, size, user, user_module);

        count++;
    }

    // Close the file
    fclose(file);

    return 0;
}