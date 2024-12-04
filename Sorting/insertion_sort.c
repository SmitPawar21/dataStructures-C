#include <stdio.h>

// INSERTION SORT

void main() {
    int arr[10];
    int i, j, curr, next;

    printf("Enter 10 values in random order: ");
    for(i=0; i<10; i++) {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<10; i++) {
        curr = arr[i]; // Value to be inserted
        j = i - 1;
        
        while(j>=0 && arr[j] > curr) {
            arr[j+1] = arr[j];
            j = j - 1;
        }

        arr[j+1] = curr;
    }

    // Display Sorted Array
    for(i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
}