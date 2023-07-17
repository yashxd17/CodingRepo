/*program for making decision whether alice will reach office*/
#include<stdio.h>
int main()
{
    float D, X, Y, N, R, totalbill ;
    printf("enter the distance=");
    scanf("%f",&D);
    printf("enter the first n kilometer=");
    scanf("%f",&N);
    printf("enter the cost for first N kms=");
    scanf("%f",&X);
    printf("enter the cost after N kms=");
    scanf("%f",&Y);
    printf("enter the amount in the wallet=");
    scanf("%f",&R);

    totalbill=X+(D-N)*Y;
    //logical condition to check wheter alice reaches office
    if(R>=totalbill)
    {
        printf("alice will reach the office\n");
    }
    printf("thank you");
}
