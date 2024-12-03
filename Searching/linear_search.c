#include <stdio.h>

void main() {
    // Array of size 10
    int arr[10];
    int i, value;
    int hasFound = 0; // Not found

    printf("Enter 10 number in any order: ");

    for(i=0; i<10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to be Search: ");
    scanf("%d", &value);

    for(i=0; i<10; i++) {

        if(arr[i] == value) {
            hasFound = 1; // Founded
            printf("Element Found. At index %d\n", i);
        }
    }

    if(hasFound == 0) {
        printf("Element Not Found\n");
    }

}