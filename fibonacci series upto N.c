/* Program for fibonacci series upto N
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:7/01/22
Date of modification:*/
#include<stdio.h>
int main()
{
    int f1,f2,f3;
    int counter, n;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    f1=0;
    f2=1;
    if (n==0)
        printf("No sequence");
    else if (n==1)
        printf("0");
    else
    {
        printf("%d\t%d\t", f1,f2);
        while (f3<n)
        {
            f3=f1+f2;
            printf("%d\t",f3);
            f1=f2;
            f2=f3;
        }
    return 0;
    }
}
