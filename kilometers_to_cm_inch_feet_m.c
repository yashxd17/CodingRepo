/* Program to convert kilometers to inches,feet,cm and m
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:7/01/22
Date of modification:*/


#include<stdio.h>
int main()
{
    float km,m,inch,cm,feet;
    printf("Enter the distance in kilometers:");
    scanf("%f",&km);
    m=km*1000;
    cm=m*100;
    inch=cm*2.54;
    feet=inch/12;
    printf("meters=%f\n",m);
    printf("centimeters=%f\n",cm);
    printf("inch=%f\n",inch);
    printf("feet=%f\n",feet);
    return 0;
}
