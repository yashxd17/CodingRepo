#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#define size 1000

struct Number
{
    int num;
	struct Number *next;
};

typedef struct Number *NODE;

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct Number));
    if(temp==NULL)
    {
        printf("No memory");
        return NULL;
    }
    else
        temp->next=NULL;

    return temp;

}

NODE read()
{
    NODE temp;
    temp=getnode();
    scanf("%d",&temp->num);
    return temp;
}

NODE insert_end(NODE head)
{
NODE temp,cur=head;
temp=read();
if(head==NULL)
    head=temp;
else{
     while(cur->next!=NULL)
        cur=cur->next;
    cur->next=temp;
    temp->next = NULL;

}
    return head;

}
int main() {
    int n, P, Q,i,num[size],temp1;
    FILE *fp1,*fp2,*fp3;
    NODE head=NULL;
    NODE temp
    
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);
    
    printf("Enter the range of numbers (P and Q): ");
    scanf("%d %d", &P, &Q);
    

    
    printf("\n");
    fp1=fopen("Input.txt","w");
    
    for(i=0;i<n;i++)
    {
        temp1=((rand()%(Q-P)));
        temp1=temp1+P;
        printf("%d\n",temp1);
        fprintf(fp1,"%d\n",temp1);
    }
    
    fclose(fp1);

    printf("%d random numbers between %d and %d written to Input.txt.\n", n, P, Q);

    fp1=fopen("Input.txt","r");
    for(i=0;i<n;i++)
    {
        temp=getnode();
        scanf("%d",temp->name,&temp->rank,&temp->age);
    }


    return 0;
}