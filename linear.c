#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

struct queue
{
int items[SIZE];
int front;
int rear;
};
int full(struct queue *q)
{
if(q->rear==(SIZE-1))
return 1;
else
return 0;
}

int empty(struct queue *q)
{
if(q->front>q->rear)
return 1;
else
return 0;
}

void insert(struct queue *q, int data)
{
q->rear=q->rear+1;
q->items[q->rear]=data;
}

int delete(struct queue *q)
{
int data=q->items[q->front];
q->front=q->front+1;
return data;
}

void display(struct queue q)
{
    int i;
printf("\n");
for( i=q.front;i<q.rear;i++)
{
printf("%d\t",q.items[i]);
}
}
int main()
{
struct queue q;
int data;
int choice;
q.rear=-1;
q.front=0;
do
{
printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
scanf("%d",&choice);
printf("\n");
switch(choice)
{
case 1: if(full(&q))
printf("\nQueue is full.");
else
{
printf("\nEnter the data to insert in the queue: ");
scanf("%d",&data);
insert(&q,data);
printf("\n%d inserted.",data);
}
break;
case 2: if(empty(&q))
printf("\nQueue is empty.");
else
{
data=delete(&q);
printf("\n%d is deleted.",data);
}
break;
case 3: if(empty(&q))
printf("\nQueue is empty.");
else
{
printf("\nElements in the Queues are: ");
display(q);
}
case 4: exit(0);
default: printf("\nPlease enter your choice again.");
}
} while (1);
}
