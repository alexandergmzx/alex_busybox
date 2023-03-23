#include <stdio.h>

// Driver code
int main(int argc, char *argv[])
{
	FILE* file_r;
	char letter;
    
    // Check that the user provided a filename to read
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

	// Opening file in reading mode
	file_r = fopen(argv[1], "r");

	if (NULL == file_r) {
        perror("file can't be opened");
        return 1;
	}

	while ((letter = fgetc(file_r)) != EOF) {
        putchar(letter);
    }

	// Closing the file
	fclose(file_r);
	return 0;
}
