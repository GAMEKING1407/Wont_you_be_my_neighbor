#include <stdio.h>
#include <errno.h>

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(dir) _mkdir(dir)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
    #define MKDIR(dir) mkdir(dir, 0755)
#endif

int main(void) {
    const char *folder = "messages";
    char filename[64];

    if (MKDIR(folder) != 0 && errno != EEXIST) {
        return 1;
    }

    for (int i = 1; i <= 100000000; i++) {
        snprintf(filename, sizeof(filename), "%s/hello_%d.txt", folder, i);

        FILE *fptr = fopen(filename, "w");
        if (fptr == NULL) {
            return 1;
        }

        fprintf(fptr, "Welcome to my neighborhood\n");
        fclose(fptr);
    }
    return 0;
}
