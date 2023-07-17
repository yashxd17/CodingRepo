#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct queue
{
    int items[SIZE];
    int front;
    int rear;
};

void createqueue(struct queue *q)
{
    q->front=-1;
    q->rear=-1;
}

int isEmpty(struct queue *q)
{
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}

int isFull(struct queue *q)
{
    if((q->rear+1)%SIZE==q->front)
        return 1;
    else
        return 0;
}

void insert(struct queue *q,int e)
{
    if(isFull(q))
    {
        printf("\nQueue is full\n");
        return;
    }
    else
    {
        if(q->front==-1)
            q->front=0;
        q->rear=(q->rear+1)%SIZE;
        q->items[q->rear]=e;
        return;
    }
}

int delete(struct queue *q)
{
    int e;
    if(isEmpty(q))
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        e=q->items[q->front];
        if(q->front==q->rear)
        {
            q->front=0;
            q->rear=-1;
        }
        else
            q->front=(q->front+1)%SIZE;
    }
    return e;
}

void display(struct queue *q)
{
    int i;
    if(isEmpty(q))
    printf("\nEmpty queue");
    else
    {
        printf("\nq->front:%d",q->front);
        printf("\nItems:");
        for(i=q->front;i!=(q->rear);i=(i+1)%SIZE)
            printf("%d ",q->items[i]);

        printf(" %d",q->items[i]);
        printf("\nq->rear:%d\n",q->rear);
    }
}

int main()
{
    int ch,x,p,e,f,n;
    struct queue q;
    createqueue(&q);

    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
                printf("Item to be inserted:");
                scanf("%d",&x);
                insert(&q,x);
                break;
        case 2:
                p=delete(&q);
                printf("%d\n",p);
                break;

        case 3:
                display(&q);
                break;
        case 4:
                return 0;
        }

    }

}
