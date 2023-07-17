#include<stdio.h>
#define SIZE 100
void count(int a[SIZE],int n)
{
    int p,neg,o,i;
    p=0;
    neg=0;
    o=0;
    for( i=0;i<n;i++)
    {
        if(a[i]>0)
            p++;
        else if(a[i]<0)
            neg++;
        else
            o++;
    }
    printf("Positive array elements=%d\n",p);
    printf("Negative array elements=%d\n",neg);
    printf("Zero array elements=%d\n",o);
}
void read_ele(int a[SIZE],int n)
{
    int i;
    printf("Enter the elements in the array\t");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    return;

}
int main()
{
    int n,a[SIZE];
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    read_ele(a,n);
    count(a,n);
    return 0;

}
