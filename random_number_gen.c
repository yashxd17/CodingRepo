//Random Number Generator
#include <stdio.h>
#include<stdlib.h>
void rand_num_generator(int P,int Q,int n) //Funtion to generate random numbers
{
    int flag=0; //flag
    int i,num;

    while(flag!=n)// to check if desired numbers are printed
    {
    for(i=0;i<n;i++)
    {
            num=rand();//number generator
            if(num>P&&num<Q)
            {
            printf("%d\n", num);
            flag++;
            }
    }
    }
}
int main() {
    int n;
    int P,Q;
    printf("Enter range:");
    scanf("%d%d",&P,&Q); //reading range
    printf("Enter desired number of variables:");
    scanf("%d",&n); //reading number of variables to be printed
    rand_num_generator(P,Q,n);// function call
   return 0;

}
