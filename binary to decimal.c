/* Program for converting binary to decimal
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
    printf("Enter the binary\n");
    scanf("%d",&n);
    i=1;
    bin=0;
    while (n!=0)
    {
        rem=n%10;
        bin=bin+rem*i;
        n=n/10;
        i=i*2;
    }
    printf("Number=%d",bin);
    return 0;
}
