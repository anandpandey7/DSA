#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *readDataFromFile(char *filename, int *size)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file");
        return NULL;
    }
    int *arr = NULL;
    int value;
    *size = 0;
    while (fscanf(file, "%d", &value) != EOF)
    {
        int *temp = (int *)realloc(arr, (*size + 1) * sizeof(int));
        if (temp == NULL)
        {
            printf("memory allocation error");
            free(arr);
            fclose(file);
            return NULL;
        }
        arr = temp;
        arr[*size] = value;
        (*size)++;
    }
    fclose(file);
    return arr;
}
int main()
{
    int *arr = NULL;
    int size = 0;
    char filename[100];
    clock_t start, end;
    printf(" enter the filename ----> ");
    scanf("%s", filename);
    start = clock();
    arr = readDataFromFile(filename, &size);
    end = clock();
    double timetaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf(" Time taken =%f", timetaken);
    if (arr == NULL)
    {
        return 1;
    }
    printf(" \n data from file ------> ");
    int i;
    for (i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    free(arr);
}