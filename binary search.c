#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2; // Find the middle index of the array

        // If the element is present at the middle itself
        if (arr[mid] == x) {
            return mid;
        }

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // Element is not present in the array
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of array
    int x = 7; // Element to search

    int result = binarySearch(arr, 0, n - 1, x); // Perform binary search

    if (result == -1) {
        printf("Element not present in array\n");
    }
    else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
