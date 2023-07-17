#include<stdio.h>
# define rsize 10
# define csize 10
void print_ele(int a[rsize][csize],int r,int c)
{
    int i,j;
    printf("The elements of the matrix are:\n");
    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
            printf(" %d ",a[i][j]);
    }
        return;
}
int sum_of_array(int a[rsize][csize],int r,int c)
{
    int s=0,i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            s+=a[i][j];
    return s;
}
int main()
{
    int c,r,a[rsize][csize],s;
    float avg;
    printf("Enter the number of columns:");
    scanf("%d",&c);
    printf("Enter the number of rows:");
    scanf("%d",&r);
    read_ele(a,r,c);
    print_ele(a,r,c);
    s=sum_of_array(a,r,c);
    printf("\nSum=%d\n",s);
    avg=(float)s/(c*r);
    printf("Average of sum =%0.2f",avg);
    return 0;

}
