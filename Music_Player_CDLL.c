#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct DATE
{
    int d,m,y;
}Date;
typedef struct song
{
    char name[100];
    char singer[50];
    Date date;
}Song;
typedef struct node
{
    struct node *prev;
    Song data;
    struct node*next;
}*NODE;
NODE getnode()
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    return p;
}
void readsong(Song *s)
{
    printf("Enter song name: ");
    scanf("%s",s->name);
    printf("Enter singer: ");
    scanf("%s",s->singer);
    printf("Date of release: ");
    scanf("%d%d%d",&s->date.d,&s->date.m,&s->date.y);
}
NODE addFront(NODE head,Song s)
{
    NODE p;
    p=getnode();
    p->prev=p;
    p->next=p;
    p->data=s;
    if(head==NULL)
    {
        head=p;
        return head;
    }
    else
    {
    NODE cur;
    cur=head->prev;
    p->prev=cur;
    cur->next=p;
    p->next=head;
    head->prev=p;
    return head;
    }

}
NODE addEnd(NODE head,Song s)
{
    NODE p;
    p=getnode();
    p->prev=p;
    p->next=p;
    p->data=s;
    if(head==NULL)
    {
        head=p;
        return head;
    }
    else
    {
        NODE cur;
        cur=head->prev;
        cur->next=p;
        p->prev=cur;
        p->next=head;
        head->prev=p;
        return head;
    }
}
NODE deleteFront(NODE head)
{
    if(head==NULL)
    {
        printf("Empty list");
        return head;
    }
    else if(head->next==head)
    {
        free(head);
        return NULL;
    }
    else{
        NODE temo=head;
        NODE cur=head->prev;
        head=head->next;
        cur->next=head;
        head->prev=cur;
        free(temp);
        return head;
    }
}
void display(NODE head)
{
    if(head==NULL)
    {
        printf("Empty list\n");
        return;
    }
    else{
        while(head->next!=head)
        {
            printf("%s\t%s\t%d-%d-%d\n",head->data.name,head->data.singer,head->data.date.d,head->data.date.m,head->data.date.y);
            head=head->next;
        }
    }

}
int main()
{
   NODE head=NULL;
   Song s;
   int ch,cnt=0,pos;
   char sin[50 ],S[100];

   while(1)
   {
       printf("1.Add song to front\n");
       printf("2.Add song at end\n");
       printf("3.Delete from front\n");
       printf("4.Delete at end\n");
       printf("5.Display\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:readsong(&s);
                  head=addFront(head,s);
                  break;
           case 5: display(head);
                  break;
       }
   }
}
