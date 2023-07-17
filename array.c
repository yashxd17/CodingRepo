#include<stdio.h>
void read_ele(int x[10], int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    return;
}
void print_ele(int x[10], int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%d", x[10]);
    return;
}
int main()
{
    int x[5];
    int n;
    read_ele(x,n);
    print_ele(x,n);
    return 0;
}
