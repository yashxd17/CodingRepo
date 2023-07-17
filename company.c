/*Program Author:Yash Deshpande
Roll no. 1050
Division J
Date of creation:27/05/22
Date of modification:*/
#include<stdio.h>
typedef struct COMPANY //Structure to store company details
{
    char c_name[15],loc[15];
    float sal;
} comp;
void read(comp c[10],int n)// reading the given information about the company in loops
{
int i;
    for(i=0;i<n;i++)
    {
        printf("Name:\nSalary:\nLocation:\n");
        scanf("%s%f%s",c[i].c_name,&c[i].sal,c[i].loc);// scan operation
    }
    return ;
}
void sal_search(comp c[10],char name,int n)// search function to search the salary of a particular company
{
int i;
    printf("Salary is:\n");
    for(i=0;i<n;i++)
        {
            if(c[i].c_name==name)
            printf("%f\n",c[i].sal);
        }
}
void sal_sort(comp c[10],int n)// sorting the salaries in descending order
{
int i,temp;
    for(i=0;i<n;i++)
    {
        if(c[i].sal<c[i+1].sal)
        {
            temp=c[i].sal;
            c[i].sal=c[i+1].sal;
            c[i+1].sal=temp;
        }
    }
    printf("Salaries in descending order:\n");
    for(i=0;i<n;i++)
    {
        printf("\n%0.2f",c[i].sal);
    }
    printf("\n");
}
void loc_search(comp c[10],char location,int n)// Displaying the companies located in a certain region
{
    int i;
    for(i=0;i<n;i++)
        {
            if(c[i].loc==location)
            printf("\n\nlist of Companies in the location are\n\n",c[i].c_name);
        }
}
int main()
{
    int n;
    comp c[10];
    char name[20],location[15];
    printf("Enter the number of companies whose data is to be stored:\n");// number of companies to be read
    scanf("%d",&n);
    read(c,n);
    printf("Enter the name of the company whose salary is to be displayed:\n");//
    scanf("%s",name);
    sal_search(c,name,n);
    sal_sort(c,n);
    printf("Enter the location needed\n");
    scanf("%s",location);
    loc_search(c,location,n);
}
