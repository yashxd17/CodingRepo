/* Program to interchange two numbers
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:7/01/22
Date of modification:*/


#include<stdio.h>
int main()
{
    int a,b;
    printf("enter the first number:");
    scanf("%d",&a);
    printf("enter the second number:");
    scanf("%d",&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("value of the first number after interchanging=%d\n",a);
    printf("value of the second number after interchanging=%d\n",b);
    return 0;

}


