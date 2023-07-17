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
    p->prev=NULL;
    p->next=NULL;
    p->data=s;
    if(head!=NULL)
    {
        p->next=head;
        head->prev=p;
    }
    head=p;
    return head;
}
NODE addEnd(NODE head,Song s)
{
    NODE cur=head;
    NODE p;
    p=getnode();
    p->prev=NULL;
    p->next=NULL;
    p->data=s;
    if(head==NULL)
    {
        head=p;

    }
    else
    {
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=p;
        p->prev=cur;
    }
    return head;
}
void display(NODE head)
{
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    while(head!=NULL)
    {
        printf("%s\t%s\t%d-%d-%d\n",head->data.name,head->data.singer,head->data.date.d,head->data.date.m,head->data.date.y);
        head=head->next;
    }
    return;
}
NODE deletefront(NODE head)
{

    if(head==NULL)
    {
        printf("Empty list");
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    NODE cur=head;
    head=head->next;
    head->prev=NULL;
    free(cur);
    return head;
}
NODE deleteEnd(NODE head)
{
    if(head=NULL)
        printf("Empty list\n");
    else if(head->next==NULL)
        free(head);
    else
        {
            NODE cur;
            while(cur->next!=NULL)
                cur=cur->next;
            cur->prev->next=NULL;
        }
        return head;
}
int count(NODE head)
{
    int cnt=0;
    NODE cur=head;
    if(head==NULL)
        cnt=0;
    else
    {
        cnt=1;
    while(cur->next!=NULL)
    {
        cnt++;
        cur=cur->next;
    }
    }
    return cnt;
}
int searchsinger(NODE head,char sin[])
{
    NODE cur=head;
    int cnt=0;
    printf("Singer: %s\n",sin);
    while(cur->next!=NULL)
    {
        if(strcasecmp(cur->data.singer,sin)==0)
        {
            printf("\t%s\t%d-%d-%-d\n",cur->data.name,cur->data.date.d,cur->data.date.m,cur->data.date.y);
            cnt++ ;
            cur=cur->next;
        }
    }
    if(cnt==0)
    {
        printf("No songs");
        return NULL;
    }
    else
    return cnt+1;
}
NODE insert_pos(NODE head,int pos,Song s)
{
    int c=0,i;
    c=count(head);

    if(pos>=1&&pos<=c)
    {
        if(pos==1)
        {
            head=addFront(head,s);
        }
        else if(pos==c)
        {
            head=addEnd(head,s);
        }
        else
        {   NODE p;
            p=getnode();
            p->prev=NULL;
            p->next=NULL;
            p->data=s;
            NODE cur=head;
            NODE pr=NULL;
            for(i=1;i<pos;i++)
                cur=cur->next;
            pr=cur->prev;
            p->next=cur;
            p->prev=pr;
            pr->next=p;
            cur->prev=p;
        }

    }
    else
        printf("Invalid position\n");
            return head;

}
NODE delete_pos(NODE head,int pos)
{
    int c=0,i;
    c=count(head);

    if(pos>=1&&pos<=c)
    {
        if(pos==1)
        {
            head=deletefront(head);
        }
        else if(pos==c)
        {
            head=deleteEnd(head);
        }
        else
        {
            NODE cur=head;
            for(i=1;i<pos;i++)
                cur=cur->next;
            cur->prev->next=cur->next;
            cur->next->prev=cur->prev;
            free(cur);
        }

    //return head;
    }
    else
        printf("INVALID\n");
     return head;
     }
NODE delete_song(NODE head,char song[100])
{

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
       printf("2.Display\n");
       printf("3.Delete from front\n");
       printf("4.Add song at end\n");
       printf("5.Delete at end\n");
       printf("6.Count list\n");
       printf("7.Singer and their songs\n");
       printf("8.Insert at a specific position\n");
       printf("9.Delete at specific position\n");
       printf("10.Delete song\n");
       printf("11.Delete all occurances\n");

       scanf("%d",&ch);
       switch(ch)
       {
           case 1:readsong(&s);
                  head=addFront(head,s);
                  break;
           case 2: display(head);
                  break;
           case 3:head=deletefront(head);
                  break;
           case 4:readsong(&s);
                  head=addEnd(head,s);
                  break;
           case 5:head=deleteEnd(head);
                  break;
           case 6:cnt=count(head);
                  printf("Number of songs in the playlist is: %d\n",cnt);
                  break;
           case 7:scanf("%s",sin);
                  cnt=searchsinger(head,sin);
                  break;
           case 8:scanf("%d",&pos);
                  readsong(&s);
                  head=insert_pos(head,pos,s);
                  break;
           case 9:scanf("%d",&pos);
                  head=delete_pos(head,pos);
                  break;
           case 10:scanf("%s",S);
                   head=delete_song(head,S);
                   break;
           case 11:scanf("%s",S);

                   break;
           default: exit(0);
       }

   }
}
