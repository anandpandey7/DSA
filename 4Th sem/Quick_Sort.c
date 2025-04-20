#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int[], int, int);
int partition(int[], int, int);
void printArray(int[], int);

int *readDataFromFile(const char *filename, int *size);
int *generateRandomNumbers(int array[], int *size);

int main()
{
    int *arr = NULL;
    int size = 0;
    int choice, count;

    printf("Choose input method:\n");
    printf("1. Read from file\n");
    printf("2. Generate random numbers\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        char filename[100];
        printf("Enter filename: ");
        scanf("%s", filename);
        arr = readDataFromFile(filename, &size);
    }
    else if (choice == 2)
    {
        printf("Enter number of random elements to generate: ");
        scanf("%d", &size);
        arr = generateRandomNumbers(arr, &size);
    }
    else
    {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Original array: \n");
    printArray(arr, size);

    clock_t start,end;
    start = clock();
    quickSort(arr, 0, size - 1);
    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    printArray(arr, size);
    printf("Time taken to sort: %.6f seconds\n", time_taken);

    free(arr);
    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to read data from file and store them in a dynamically allocated array
int *readDataFromFile(const char *filename, int *size)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }

    int *arr = NULL; // Initialize the array to NULL
    int value;
    *size = 0;

    // Dynamically read integers until EOF is encountered
    while (fscanf(file, "%d", &value) != EOF)
    {
        // Dynamically allocate/reallocate memory for the array
        int *temp = (int *)realloc(arr, (*size + 1) * sizeof(int));
        if (temp == NULL)
        {
            printf("Memory allocation error.\n");
            free(arr); // Free previously allocated memory
            fclose(file);
            return NULL;
        }

        arr = temp;         // Assign the new block to arr
        arr[*size] = value; // Store the value in the array
        (*size)++;          // Increase the size count
    }

    fclose(file);
    return arr; // Return the dynamically allocated array
}

int *generateRandomNumbers(int array[], int *size)
{
    // Seed the random number generator using the current time
    srand(time(0));

    // Allocate memory for the array
    array = (int *)malloc(*size * sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Generate random integers and store them in the array
    for (int i = 0; i < *size; i++)
    {
        array[i] = rand() % 100; // Random integers from 0 to 99
    }

    printf("Generated random numbers:\n");
    for (int i = 0; i < *size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return array;
}
