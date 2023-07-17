/* Program to calculate the distance covered by audi
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:7/01/22
Date of modification:*/

#include<stdio.h>
int main()
{
    float dist, mil,price,amt;
    printf("enter the mileage:");
    scanf("%f",&mil);
    printf("enter the petrol price:");
    scanf("%f",amt);
    dist=mil*amt/price;
    printf("distance=%f",dist);
    return 0;

}


