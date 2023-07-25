#include <stdio.h>
#include <stdlib.h>

void swap(int x, int y, int *arr){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int pIndex = start; // partition index = pIndex
    for(int i=start; i<end; i++){
        if(arr[i] <= pivot){
            swap(i, pIndex, arr);
            pIndex++;
        }
    }
    swap(pIndex, end, arr);
    return pIndex;
}

void quicksort(int *arr, int start, int end){
    if(start < end){
        int pIndex = partition(arr, start, end);
        quicksort(arr, start, pIndex-1);
        quicksort(arr, pIndex+1, end);
    }
}

int main(int argc, char const *argv[])
{
    int arr[7] = {7,8,3,5,2,1,9};
    quicksort(arr, 0, 6);
    
    for(int i=0; i<7; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
