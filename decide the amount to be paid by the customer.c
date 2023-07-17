/* Program to decide the amount to be paid by the customer
Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:28/01/22
Date of modification:*/

#include<stdio.h>
int main()
{
    float purchase_amt,discount, bill;
    printf("Enter the purchase amount\n");
    scanf("%f",&purchase_amt);
    if (purchase_amt<=100)
    {
        bill=purchase_amt;
        printf("%f",bill);
    }
    else if(purchase_amt<=200)
    {
        bill= purchase_amt -0.05*purchase_amt;
        printf("%f",bill);
    }
    else if(purchase_amt<=300)
    {
        bill= purchase_amt -0.075*purchase_amt;
        printf("%f",bill);
    }
    else
    {
        bill= purchase_amt -0.1*purchase_amt;
        printf("%f",bill);
    }
    return 0;
}
