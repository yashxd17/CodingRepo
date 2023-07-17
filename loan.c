
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

typedef struct loaApplicant
{
    char n[20];
    char t[5];
    int d;
}LOAN;

struct queue
{
    LOAN l[9];
    int front,rear;
};
void initstack(struct queue *q)
{
    q->front=0;
    q->rear=-1;
}

void enQueue(struct queue *q,LOAN l)
{
    q->rear++;
    q->l[q->rear]=l;
}
LOAN deQueue(struct queue *q)
{
    LOAN l;
    l=q->l[q->front];
    q->front++;
    return l;
}
int empty(struct queue *q)
{
    if(q->front>q->rear)
        return 1;
    else
        return 0;
}
int main()
{
    struct queue q1,q2;
    initstack(&q1);
    initstack(&q2);
    int N;
    int cnt=0;
    printf("\nEnter number of applicants: ");
    scanf("%d",&N);
    if(N<1&&N>10)
        return 0;
    LOAN l;int i;
    for(i=0;i<N;i++)
    {
        printf("\nEnter applicant details:\n");
        printf("1.Name  2.Type of loan  3.Amount\n");
        scanf("%s%s%d",l.n,l.t,&l.d);
        enQueue(&q1,l);
    }
    int s=0;
    printf("\n");
    printf("Short term Application details\n");
    while(!empty(&q1))
    {
        l=deQueue(&q1);
        if(strcmp(l.t,"short")==0)
        {
            if(l.d<=50000)
            {
                printf("%s  %s  %d\n",l.n,l.t,l.d);
                s=s+l.d;
                cnt++;
            }
        }
        else
        {
            enQueue(&q2,l);
        }

    }
    printf("%d\n",s);
    s=0;
    printf("Long term Application details\n");
    while(!empty(&q2))
    {
        l=deQueue(&q2);
            if(l.d<=100000)
            {
                printf("%s  %s  %d\n",l.n,l.t,l.d);
                s=s+l.d;
                cnt++;
            }
    }
    printf("%d\n%d\n",s,cnt);

}

