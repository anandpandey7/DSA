#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MergeSort(int [],int,int);
void Merge(int [],int,int,int);

void printArray(int [], int );

int* readDataFromFile(const char *filename, int *size);
int* generateRandomNumbers(int array[], int *size);

int main() {
    int *arr = NULL;
    int size = 0, low, high;
    int choice, count;
    
    printf("Choose input method:\n");
    printf("1. Read from file\n");
    printf("2. Generate random numbers\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        char filename[100];
        printf("Enter filename: ");
        scanf("%s", filename);
        arr=readDataFromFile(filename, &size);
    } else if (choice == 2) {
        printf("Enter number of random elements to generate: ");
        scanf("%d", &size);
        arr=generateRandomNumbers(arr, &size);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Original array: \n");
    printArray(arr, size);

    clock_t start = clock();
    
    low=0;
	high=size-1;
	MergeSort(arr,low,high);

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    printArray(arr, size);
    printf("Time taken to sort: %.6f seconds\n", time_taken);

    free(arr);
    return 0;
}

void MergeSort(int a[],int low,int high)
{
  int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,mid,high);

	}
}

void Merge(int a[],int low,int mid,int high)
{
	int h = low, i = 0, j = mid + 1;
    int b[high-low+1];

    // Merge the two halves
    while (h <= mid && j <= high) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h++;
        } else {
            b[i] = a[j];
            j++;
        }
        i++;
    }

    // Copy the remaining elements from the first half (if any)
    while (h <= mid) {
        b[i++] = a[h++];
    }

    // Copy the remaining elements from the second half (if any)
    while (j <= high) {
        b[i++] = a[j++];
    }

    // Copy back the merged elements to the original array
    for (i = 0; i <= high - low; i++) {
        a[low + i] = b[i];
    }
}



void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to read data from file and store them in a dynamically allocated array
int* readDataFromFile(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }
    
    int *arr = NULL;  // Initialize the array to NULL
    int value;
    *size = 0;

    // Dynamically read integers until EOF is encountered
    while (fscanf(file, "%d", &value) != EOF) {
        // Dynamically allocate/reallocate memory for the array
        int *temp =(int*) realloc(arr, (*size + 1) * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation error.\n");
            free(arr);  // Free previously allocated memory
            fclose(file);
            return NULL;
        }

        arr = temp;  // Assign the new block to arr
        arr[*size] = value;  // Store the value in the array
        (*size)++;  // Increase the size count
    }

    fclose(file);
    return arr;  // Return the dynamically allocated array
}


int* generateRandomNumbers(int array[], int *size) {
    // Seed the random number generator using the current time
    srand(time(0));
    
    // Allocate memory for the array
    array = (int *)malloc(*size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Generate random integers and store them in the array
    for (int i = 0; i < *size; i++) {
        array[i] = rand() % 100; // Random integers from 0 to 99
    }
    
    printf("Generated random numbers:\n");
    for (int i = 0; i < *size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
  return array;

}

