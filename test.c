#include <stdio.h>
#include<stdlib.h>

//Bubble sort algorithm to sort an array of integers in ascending order 
void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    // Iteration 
    for (i = 0; i < n - 1; i++) {

        // Compare adjacent elements and swap them if they are in the wrong order 
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Print an array of integers 
void printArray(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main program 
int main()
{
    int arr[100];
    int n, i;

    // Prompt the user to enter the number of elements in the array 
    printf("Enter the number of elements in array\n");
    scanf("%d", &n);

    // Generate a random set of 'n' numbers
    for (i = 0; i < n; i++) 
    {
        arr[i]=rand();
    }

    // Sort the array using bubble sort algorithm 
    bubbleSort(arr, n);

    // Print the sorted array 
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}