#include <stdio.h>

// BUBBLE SORT

void main() {
    int arr[10];
    int i, j, temp;

    printf("Enter 10 values in random order: ");
    for(i=0; i<10; i++) {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<10; i++) {
        for(j=0; j<10-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Display the Sorted Array
    for(i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
}