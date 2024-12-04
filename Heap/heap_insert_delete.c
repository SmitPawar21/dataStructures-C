#include <stdio.h>
#define MAX 100

// Global Max Heap (Array representation)
int arr[MAX];
int n = 0;

void insert() {
    int value, i, parent, temp;

    printf("Enter value for the node: ");
    scanf("%d", &value);

    arr[n] = value;
    n++;

    i = n - 1;
    parent = (i-1)/2;
    while(i>0 && (arr[parent] < arr[i])) {
        temp = arr[parent];
        arr[parent] = arr[i];
        arr[i] = temp;

        i = parent;
        parent = (i - 1) / 2;
    }
}

void heapify(int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    int temp;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(largest);
    }
    else{
        return;
    }
}

void delete() {
    
    arr[0] = arr[n-1];
    n--;

    heapify(0);

}

void display() {
    int i;

    printf("Max Heap => ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() 
{
    int exit = 0; // Exit is False
    int choice;

    while(exit == 0) {
        printf("1: Insert\n");
        printf("2: Delete\n");
        printf("3: Display\n");
        printf("0: Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1: insert();
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 0: exit = 1; // Exit is True
            break;
            default: printf("Kindly enter Valid Choice\n");
        }
    }
}