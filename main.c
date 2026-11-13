#include <stdio.h>

int main() {
    FILE *fptr = fopen("hello.txt", "w");

    if (fptr == NULL) {
        printf("Error: Could not create the file.\n");
        return 1;
    }

    fprintf(fptr, "Hello - Daniel\n");

    fclose(fptr);

    printf("File created successfully.\n");
    return 0;
}
