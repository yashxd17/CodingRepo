// C program for implementation of Bubble sort
#include <stdio.h>

void bubbleSort(int arr[], int n)
{
	int i, j,temp;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }

}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[100];
	int n;
	printf("Enter the number of elements in array\n");
	scanf("%d",&n);
	int i;
	printf("Enter the elements in array\n");
	for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
