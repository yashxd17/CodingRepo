#include<stdio.h>
#include<stdlib.h>
main ()\
{
int *p;
printf("the value =%u\n",&p);
p=(int*)malloc(sizeof(int));
printf("Enter a value\n");
scanf("%d",p);
printf("the value =%d\n",p);
printf("the value =%u\n",*p);
}
