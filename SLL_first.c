/*Program to demonstrate basic SLL operations*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct candidate
{
	char name[25];
	int rank;
    int age;
	struct candidate *next;
};



typedef struct candidate *NODE;
// Function to allocate memory dynamically using malloc() function
NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct candidate));
    if(temp==NULL)
    {
        printf("No memory");
        return NULL;
    }
    else
        temp->next=NULL;

    return temp;

}
//function to read details of the candidate
NODE read()
{
    NODE temp;
    temp=getnode();
    printf("\nENTER DETAILS\n");
    scanf("%s%d%d",temp->name,&temp->rank,&temp->age);
    return temp;
}
// to display(traverse) all elements of the list
void display(NODE head)
{
     NODE cur;
     cur=head;
     if(head==NULL)
           printf("EMPTY LIST");
     else
    {
        while(cur!=NULL)
        {
             printf("%s\t%d\t%d\n",cur->name,cur->rank,cur->age);
             cur=cur->next;
        }
    }
}
// function to insert a node in the beginning of the list
NODE insert_front(NODE head)
{
  NODE temp;
  temp=read();

  if(head==NULL)
    head = temp;
  else
  {

    temp->next=head;
    head=temp;
  }
  return head;

}
// function to insert a node at the end of the list
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
///function to insert a node at a specified position of the list(based on the name)
NODE insert_pos(NODE head, char NAME[30])
{
 NODE cur=head, temp, prev=NULL;
 temp=read();
 if(head==NULL)
   head = temp;
 else
 {
   do{
       if(strcmp(cur->name,NAME)==0)
       {
          temp->next= cur->next;
          cur->next = temp;
           return head;
       }
         cur=cur->next;
     }while(cur!=NULL);
 }
   return head;
}
// function to count the number of nodes in the list
int count(NODE head)
{   NODE temp=head;
     if (head == NULL)
        return 0;
    int c=0;
    while(temp !=NULL)
    {
        c++;
        temp = temp->next;

    }
    return c;

}
//function to search a node based on the name of the candidate
int search(NODE head, char sname[20])
{
  NODE temp = head;;
  if(head  == NULL)
    return 0;
  while(temp != NULL)
  {
      if(strcmp(temp->name,sname)==0 )
         {
             printf("%s\t %d \t %d\n",temp->name,temp->rank, temp->age);
             return 1;

         }
         temp=temp->next;
  }
  return 0;

}
NODE specific_pos(NODE head,int pos)
{
    NODE temp=head;
    int n;
    n=count(head);
    if(pos>=1 && pos<=n+1)
    {
        NODE newnode=read();
        if(pos==1)
        {
            newnode->next=head;
            head=newnode;
            return head;
        }
        if(pos==n+1)
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            return head;
        }
        else
        {
            int i;
            for(i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            return head;
        }

    }
    else
        printf("Position more than number of nodes\n");
    return head;
}
NODE delete_at_position(NODE head,int pos)
{
    if(pos<1||pos>count(head))
    {
        printf("Invalid position");
        return head;
    }
    NODE cur=head;
    NODE prev=NULL;
    if(pos==1)
    {
        head=head->next;
        printf("Name:%s\n",cur->name);
        printf("Rank:%d\n",cur->rank);
        printf("Age:%d\n",cur->age);
        free(cur);
        return head;

    }
    int i;
    for(i=1;i<pos;i++)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    printf("Name:%s\n",cur->name);
    printf("Rank:%d\n",cur->rank);
    printf("Age:%d\n",cur->age);
    free(cur);
    return head;

}
NODE delete_namenode(NODE head,char NAME[30])
{
    NODE cur=head;
    NODE prev=NULL,target=NULL;
    if(strcasecmp(cur->name,NAME)==0)
    {
        head=head->next;
        target=cur;
        free(target);
        return head;
    }
   do
    {
        prev=cur;
        cur=cur->next;
        if(strcasecmp(cur->name,NAME)==0)
        {
            prev->next=cur->next;
            target=cur;
            free(target);
        }
    } while(cur->next!=NULL);

    return head;


}

int main(){
 NODE head=NULL;
 NODE newnode;
 int ch,c,pos;
 char NAME[30];
 while(1)
 {
   printf("\n1.Insert front \n2.Insert_end \n3.Display \n4.insert position\n5.count\n6.search \n7.Insert at specific position\n8.Delete at specific position \n9.Delete a name\n 10.exit\n");
   scanf("%d",&ch);
   switch(ch){
            case 1: head=insert_front(head);
                    break;
            case 2: head =insert_end(head);
                    break;

            case 3:display(head);
                    break;
            case 4 : printf("Enter the name after which you want to insert\n");
                     scanf("%s",NAME);
                     head=insert_pos(head,NAME);
                     break;
            case 5:
                    c=count(head);
                     printf("The number of nodes  = %d",c);
                     break;
            case 6: printf("ENter name to search \n");
                     scanf("%s",NAME);
                     c= search(head , NAME);
                     if(c==1)
                        printf("Search is successful \n");
                     else
                         printf("Search Not successful\n");
                     break;
             case 7:printf("Enter the position to insert:\n");
                        scanf("%d",&pos);

                        head=specific_pos(head,pos);
                        break;
             case 8:printf("Enter the position to delete:\n");
                        scanf("%d",&pos);
                        head=delete_at_position(head,pos);
                        break;
             case 9:printf("Enter the name \n");
                    scanf("%s",NAME);
                    head=delete_namenode(head,NAME);
                    break;
            default : exit(0);
            }
 }
}