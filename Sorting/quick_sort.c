#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for(j=low; j<high; j++) {
        if(arr[j] < pivot) {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quicksort(int arr[], int low, int high) {
    int pi;

    //base condition
    if(low >= high) {
        return;
    }

    pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
}

void main() {
    int arr[10];
    int i;

    printf("Enter 10 random values: ");
    for(i=0; i<10; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, 9);

    printf("Sorted Array: ");
    for(i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
}