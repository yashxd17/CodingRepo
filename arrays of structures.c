#include<stdio.h>
typedef struct DATE
{
    int dd,mm,yy;
}D;
typedef struct NAME
{
    char FN[10],MN[10],LN[10];
}N;
typedef struct PERSON
{
    N n;
    float salary;
    D d;
    int exp;
}EMP;
void read(EMP E[10],int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        printf(" Person details:\n %d",i+1);
        scanf("%s%s%s%f%d%d%d%d",E[i].n.FN,E[i].n.MN,E[i].n.LN,&E[i].salary,&E[i].d.dd,&E[i].d.mm,&E[i].d.yy,&E[i].exp);
    }

    return ;
}
void display(EMP E[10],int m)
{
    int i;
    for(i=0;i<m;i++)
    printf("\n Name is:%s %s %s \n Salary:%0.2f\n Date of birth:%d-%d-%d\n Years of experience:%d",E[i].n.FN,E[i].n.MN,E[i].n.LN,E[i].salary,E[i].d.dd,E[i].d.mm,E[i].d.yy,E[i].exp);
    return;
}
int main()
{
    EMP E[10];
    int m;
    printf("Enter the number of employees you want to store data of(<=10):");
    scanf("%d",&m);
    read(E,m);
    display(E,m);

}
