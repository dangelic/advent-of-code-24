// day1.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "days.h"

#define MAX_LINES 1000
#define MAX_LENGTH 256

// for quicksort
int compare_int(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void stage1(FILE *file)
{
    int left[MAX_LINES];
    int right[MAX_LINES];
    int delta = 0;

    int count = 0;

    char line[MAX_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        // split  line into two parts based on whitespace
        char *token1 = strtok(line, " \t");
        char *token2 = strtok(NULL, " \t");

        if (token1 != NULL && token2 != NULL)
        {
            left[count] = atoi(token1);
            right[count] = atoi(token2);
            count++;
        }
    }

    int num = sizeof(left) / sizeof(left[0]);

    // sorting the arrays asc
    qsort(left, num, sizeof(int), compare_int); // array, number of elements, size of one element, compare function pointer
    qsort(right, num, sizeof(int), compare_int);

    for (int i = 0; i < count; i++)
    {
        delta += abs(left[i] - right[i]);
    }

    printf("Delta total: %d", delta);
}

void day1(FILE *file, int stage)
{
    if (stage == 1)
    {
        stage1(file);
    }
    else
    {
        stage1(file);
    }
}
