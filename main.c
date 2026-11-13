#include <stdio.h>

int main() {
    char filename[32];

    for (int i = 1; i <= 10; i++) {
        snprintf(filename, sizeof(filename), "hello_%d.txt", i);

        FILE *fptr = fopen(filename, "w");
        if (fptr == NULL) {
            printf("Error: Could not create %s.\n", filename);
            return 1;
        }

        fprintf(fptr, "Hello - Daniel\n", i);
        fclose(fptr);
    }

    printf("Successfully created 10 files.\n");
    return 0;
}
