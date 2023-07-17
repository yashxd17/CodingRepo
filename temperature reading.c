#include<stdio.h>
#define R 15
#define C 15

void read_ele(int a[C][R],int N,int M)
{
    int i;
    int j;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
        {
        scanf("%d",&a[i][j]);
        }
    int max_temp,cnt,sum=0;
    float avg=0;
    for(j=0;j<M;j++)
    {
        max_temp=0;
        cnt=0;
        for(i=0;i<N;i++)
        {
            if(a[i][j]>max_temp)
            max_temp=a[i][j];
        }
        cnt++;
        if(cnt<M)
            printf("maximum temperature in city %d is : %d\n",cnt,max_temp);

    }
    for(j=0;j<M;j++)
    {
        sum=0;
        avg=0;
        for(i=0;i<N;i++)
        {
            sum=sum+a[i][j];
        }
        avg=(float)sum/N;
            printf("Predicted temperature on the next day is %f\n",avg);
    }
    return;
}

int main()
{
    int a[C][R],M,N;
    printf("Enter the number of cities :\n");
    scanf("%d",&M);
    printf("Enter the number of days of observation :\n");
    scanf("%d",&N);
    read_ele(a,N,M);
    return 0;
}
