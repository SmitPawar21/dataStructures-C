#include<stdio.h>

#define MAX 100

int arr[MAX];
int n = 0;

void insert() {
    int i, j, value, parent, temp;

    printf("Enter 10 values for array: \n");
    for(j=0; j<10; j++) {
        printf("Value: ");
        scanf("%d", &value);

        arr[n] = value;
        n++;

        i = n-1;
        parent = (i-1)/2;

        while(i>0 && (arr[parent] < arr[i])) {
            temp = arr[parent];
            arr[parent] = arr[i];
            arr[i] = temp;

            i = parent;
            parent = (i-1)/2;
        }
    }
}

void heapify(int i, int n) {
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;
    int temp;

    if(left < n && (arr[left] > arr[largest])) {
        largest = left;
    }

    if(right < n && (arr[right] > arr[largest])) {
        largest = right;
    }

    if(largest != i) {
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(largest, n);
    }
    else{
        return;
    }
}

void display() {
    int i;

    printf("Sorted Array: ");
    for(i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heap_sort() {
    int start, end, temp;

    start = 0;
    end = n-1;

    while(end >= start) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        heapify(start, end);

        end--;
    }

}

void main() {
    int i;

    insert();

    heap_sort();

    display();

}