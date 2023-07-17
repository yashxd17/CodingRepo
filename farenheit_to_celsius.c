/* Program to convert farenheit to celsius
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:7/01/22
Date of modification:*/


#include<stdio.h>
int main()
{
    float faren, celsius;
    printf("Enter the temperature in farenheit:");
    scanf("%f",&faren);
    celsius=5*(faren-32)/9;
    printf("Celsius=%f",celsius);
    return 0;
}
