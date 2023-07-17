#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *dynamicArr;
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);

    //Dynamic memory allocation for optimization
    dynamicArr= (int*)malloc(n * sizeof(int));
    if(dynamicArr==NULL)
    {
        printf("No memory");
        return 0;
    }  

    printf("Array elements:\n ");
    //Using the memory allocated 
    for(int i=0;i<n;i++)
    {
        dynamicArr[i]=i+1;
        printf("%d ", dynamicArr[i]);
        
    }
    free(dynamicArr);
    return 0;

}