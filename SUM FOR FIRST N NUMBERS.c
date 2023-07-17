/* Program to  calculate the sum of first n numbers
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:7/01/22
Date of modification:*/
#include<stdio.h>
int main()
{
    int N;
    int i=1;
    int sum=0;
    printf("Enter the value of N\n");
    scanf("%d",&N);
    while (i<=N)
    {
        sum=sum+i;
        i++;
    }
    printf("Sum =%d", sum);
    return 0;
    }
