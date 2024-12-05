#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int i;
    int L[n1], R[n2];
    int x=0, y=0, z=left;

    for(i=0; i<n1; i++) {
        L[i] = arr[left + i];
    }

    for(i=0; i<n2; i++) {
        R[i] = arr[mid + i + 1];
    }

    while(x < n1 && y < n2) {
        if(L[x] <= R[y]) {
            arr[z++] = L[x++];
        }
        else{
            arr[z++] = R[y++];
        }
    }
    while(x < n1) {
        arr[z++] = L[x++];
    }
    while(y < n2) {
        arr[z++] = R[y++];
    }

}

void merge_sort(int arr[], int left, int right) {
    int mid;

    if(left >= right) {
        return;
    }

    mid = (left + right)/2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void main() {
    int arr[10];
    int i;

    printf("Enter 10 random values: ");
    for(i=0; i<10; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, 9);

    printf("Sorted Array: ");
    for(i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
}