#include<stdio.h>
#include<stdlib.h>//to use exit function
#define SIZE 50
struct queue
{
    int a[SIZE];
    int front,rear;
};

void insert(struct queue *q,int data)
{
    if(q->rear==SIZE-1)
    printf("Queue overflown\n");
    else
    q->a[++q->rear]=data;
}
int delete(struct queue *q)
{
    int data;
    if(q->front>q->rear)
    {
        printf("Queue underflown");
        return -1;
    }
    else
    {
        data=q->a[q->front++];
        return data;
    }
}
void display( struct queue q)
{
    int i;
    if(q.front>q.rear)
    printf("Queue underflown");
    else
    {
    for(i=q.front;i<q.rear;i++)
        printf("%d\t",q.a[i]);
    }
}

int main()
{
    struct queue q;
    int data;
    int ch;
    q.rear=-1;
    q.front=0;

    while(1)
    {
        printf("press\n1.to insert\n2.to delete\n3.to display\n4.to exit");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:printf("enter the element to be inserted\n");
                       scanf("%d",&data);
                       insert(&q,data);
                       break;
                case 2:data=delete(&q);
                       printf("the deleted data is %d",data);
                       break;
                case 3:display(q);
                       break;
                case 4:exit(0);
                       break;
        }
    }
    return 0;
}
