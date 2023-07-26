#include <stdio.h>
#include <stdlib.h>

void merge(int left_arr[], int right_arr[], int arr[], int nl, int nr){
    int i=0; int j=0; int k=0;
    
    while(i<nl && j<nr){
        if(left_arr[i] < right_arr[j]){
            arr[k] = left_arr[i];
            i++;
        }
        else{
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while(i<nl){
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while(j<nr){
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int n){
    if(n==1){
        return; 
    }
    else{
        int mid = n/2;
        int left_arr[mid];
        int right_arr[n-mid];
        for(int i=0; i<mid; i++){
            left_arr[i] = arr[i];
        }
        for(int i=0; i<n-mid; i++){
            right_arr[i] = arr[mid+i];
        }
        mergesort(left_arr, mid);
        mergesort(right_arr, n-mid);
        merge(left_arr, right_arr, arr, mid, n-mid);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        arr[i] = x;
    }

    mergesort(arr, n);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
