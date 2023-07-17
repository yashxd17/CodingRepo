#include<stdio.h>
#include<stdlib.h>
struct emp{
    int eid;
    char name[20];
    float sal;
};
int main ()
{
 struct emp *p;
 printf("%d\n",&p);
 p=(struct emp *)malloc(sizeof(struct emp));
 printf("%d\n",p);
 printf("Enter employee details\n");
 scanf("%d%s%f",&p->eid,p->name,&p->sal);

 printf("Employee details are\n");
 printf("%d\n%s\n%f\n",p->eid,p->name,p->sal);


 printf("%d\n",p);
 printf("Enter employee details\n");
 scanf("%d%s%f",&p->eid,p->name,&p->sal);

 printf("Employee details are\n");
 printf("%d\n%s\n%f\n",p->eid,p->name,p->sal);

}
