#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
    arr[i] = x;
    arr[i+1] = y;
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
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                swap(arr, i, arr[i], arr[i+1]);
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
