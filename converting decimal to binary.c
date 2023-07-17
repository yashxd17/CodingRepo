/* Program for converting decimal to binary
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:7/01/22
Date of modification:*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,bin,rem,i;
    printf("Enter the number\n");
    scanf("%d",&n);
    i=1;
    bin=0;
    while (n!=0)
    {
        rem=n%2;
        bin=bin+rem*i;
        n=n/2;
        i=i*10;
    }
    printf("Binary=%d",bin);
    return 0;
}
