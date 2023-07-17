/* Program to calculate the sum of two numbers
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:7/01/22
Date of modification:*/


#include<stdio.h>
int main()
{
    float aggre,percent,m1,m2,m3,m4,m5,sum;
    printf("enter the marks in subject 1: \n");
    scanf("%f",&m1);
    printf("enter the marks in subject 2: \n");
    scanf("%f",&m2);
    printf("enter the marks in subject 3: \n");
    scanf("%f",&m3);
    printf("enter the marks in subject 4: \n");
    scanf("%f",&m4);
    printf("enter the marks in subject 5: \n");
    scanf("%f",&m5);
    sum=m1+m2+m3+m4+m5;
    aggre=(sum)/500;
    percent=aggre*100;
    printf("Aggregate marks=%f\n",aggre);
    printf("Percentage=%f",percent);
    return 0;
}
