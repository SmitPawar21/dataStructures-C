#include <stdio.h>

void main() {
    // Sorted array of 10 elements
    int arr[10];
    int i;
    int start = 0, end = 9;
    int mid = (start + end) / 2;
    int value;
    int hasFound = 0; // Not Found

    printf("Enter Sorted values: ");
    for(i=0; i<10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to be Search: ");
    scanf("%d", &value);

    while(start <= end) {
        if(arr[mid] == value) {
            hasFound = 1; // Founded
            printf("Element Found! At index %d\n", mid);
            break;
        }

        else if(value > arr[mid]) {
            start = mid+1;
        }

        else {
            end = mid-1;
        }

        mid = (start + end) / 2;
    }

    if(hasFound == 0) {
        printf("Element Not Found\n");
    }

}