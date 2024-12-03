#include <stdio.h>

// Global Sorted Array haiii 
int arr[10];

// Perform karo Sequential Search in a given block
int sequentialSearch(int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == val) {
            return i;  // Found the value yayy
        }
    }
    return -1;  // Not found in the block oopss
}

// Index Sequential Search Function
int indexSequentialSearch(int n, int val) {
    int blockSize = 3;  // Block size, can be adjusted based on requirements
    int index = -1;
    
    // Start with index positions (based on block size)
    for (int i = 0; i < n; i += blockSize) {
        if (arr[i] == val) {
            return i;  // Return the index if value is found
        }
        else if (arr[i] > val) {
            // If the current block element is larger than val, search sequentially within the block
            index = sequentialSearch(i - blockSize + 1, i - 1, val);
            if (index != -1) {
                return index;  // Value found in the block
            }
            break; // If the element is smaller, no need to check further blocks
        }
    }
    
    // Perform a linear search in the last block or the remaining portion of the array
    if (index == -1) {
        index = sequentialSearch(n - blockSize, n - 1, val);
    }
    
    return index;  // Return the index or -1 if not found
}

int main() {
    int n = 10;
    int value, result;
    
    // Input array of sorted values
    printf("Enter 10 sorted values in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input value to search
    printf("Enter the value to be searched: ");
    scanf("%d", &value);

    // Perform index sequential search
    result = indexSequentialSearch(n, value);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    }
    else {
        printf("Element not found\n");
    }

    return 0;
}
