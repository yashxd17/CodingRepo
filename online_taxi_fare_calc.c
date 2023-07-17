/* Program to calculate the online taxi fare
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:7/01/22
Date of modification:*/

#include<stdio.h>
int main()
{
    float dist,x,y,n,bill;
    printf("Enter the minimum distance:");
    scanf("%f",&n);
    printf("Enter the cost for first n kilometers:");
    scanf("%f",&x) ;
    printf("Enter the cost after n kilometers:");
    scanf("%f",&y);
    printf("enter the total distance covered:");
    scanf("%f",&dist);
    bill=x+(dist-n)*y;
    printf("total bill=%f",bill);
    return 0 ;
}
