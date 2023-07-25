// count sort

#include <stdio.h>

int max(int arr[], int n){
    int max_element = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > max_element){
            max_element = arr[i];
        }
    }
    return max_element;
}

void countSort(int arr[], int n){
    int c = max(arr, n);
    int count_arr[c+1];
    for(int i=0; i<c+1; i++){
        count_arr[i] = 0;
    }

    for(int i=0; i<n; i++){
        count_arr[arr[i]]++;
    }

    for(int i=1; i<c+1; i++){
        count_arr[i]+=count_arr[i-1];
    }

    int final_arr[n];
    for(int i=0; i<n; i++){
        final_arr[--count_arr[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = final_arr[i];
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    countSort(arr, n);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}