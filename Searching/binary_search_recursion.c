#include <stdio.h>

// Global Sorted Array of size 10
int arr[10];

// This returns 1 if Element is Found
int binarySearch(int s, int e, int mid, int val) {

    // Failure Condition
    if(s > e) {
        return 0;
    }

    // Successfull Condition
    if(arr[mid] == val) {
        return 1;
    }

    else if(val > arr[mid]) {
        s = mid+1;
    }
    else if(val < arr[mid]) {
        e = mid-1;
    }

    mid = (s+e)/2;

    return binarySearch(s, e, mid, val);
}

void main() {
    int i;
    int start = 0, end = 9;
    int mid = (start + end) / 2;
    int value;
    int answer;

    printf("Enter 10 Sorted values in array: ");
    for(i=0; i<10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to be Searched: ");
    scanf("%d", &value);

    answer = binarySearch(start, end, mid, value);

    if(answer == 1) {
        printf("Element Found");
    }

    else {
        printf("Element Not Found");
    }

}