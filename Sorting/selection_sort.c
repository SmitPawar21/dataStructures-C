#include <stdio.h>

// SELECTION SORT

void main() {
    int arr[10];
    int i, j, min, temp;

    printf("Enter 10 values in random order: ");
    for(i=0; i<10; i++) {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<10; i++) {
        min = i;
        
        for(j=i; j<10; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swapping the smallest element with ith position
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    // Display the sorted Array
    printf("Sorted Array: ");
    for(i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
}