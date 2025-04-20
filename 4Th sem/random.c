#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int * generateRandomNo(int arr[], int size){
    srand(time(0));
    arr = (int *) malloc(size * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed");
        return NULL;

    }
    int i;
    for(i=0; i<size; i++)    arr[i] = rand()%100;

    return arr;
    
}
int main(){
    int size;
    clock_t start, end;
    int *arr = NULL;
    printf("Enter the no. of random numbers you want to generate : ");
    scanf("%d",&size);
    start = clock();
    arr = generateRandomNo(arr,size);
    end = clock();
    double timetaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Randomlly generated %d numbers are :\n",size);
    int i;
    for(i=0; i<size; i++)    printf("%d ",arr[i]);
    printf("\nAnd time taken to generate these numbers is : %f",timetaken);
    return 0;

}