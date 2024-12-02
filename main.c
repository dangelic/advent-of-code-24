#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARG1 "-day"
#define ARG2 "-stage"

int main(int argc, char *argv[])
{
    int day = 0;
    int stage = 0;
    char filename[256];
    char buffer[50000];

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], ARG1) == 0 && i + 1 < argc)
        {
            day = atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], ARG2) == 0 && i + 1 < argc)
        {
            stage = atoi(argv[i + 1]);
            i++;
        }
    }

    // read day file
    snprintf(filename, sizeof(filename), "puzzle_input/day_%d_stage_%d.txt", day, stage);
    FILE *file = fopen(filename, "r");
        if (file == NULL) {
        printf("file not found: %s", filename);
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);    
}