/* Program for sine function computation
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:7/01/22
Date of modification:*/
#include<stdio.h>
#include<math.h>
int main ()
{
    int n,fact=1,i,sign=-1;
    float sum,x;
    printf("Value of n:");
    scanf("%d",&n);
    printf("Angle in degree:");
    scanf("%f",&x);
    x=x*3.14/180;
    sum=x;
    printf("Angle in radian=%f",x);
    for(i=3;i<=n;i+=2)
    {
        fact=fact*i*(i-1);
        sum=sum+sign*(pow(x,i)/fact);
        sign=sign*-1;
    }
    printf("\nSum=%0.4f",sum);
    return 0;
}
