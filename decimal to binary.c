#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
struct stack
{
    int top;
    int a[SIZE];
};
int isfull(struct stack *s)
{
    if(s->a[s->top]==SIZE-1)
        return 1;
    else
        return 0;
}
void push(struct stack *s,int e)
{
        s->top++;
        s->a[s->top]=e;
    return;
}
int isEmpty(struct stack *s)
{
    return s->top==-1;
}
int pop(struct stack *s)
{
    int e;
    e=s->a[s->top];
    s->top=s->top-1;
    return e;
}
void printStack(struct stack *s) {
    printf("Stack: ");
    for (int i = s->top ; i >= 0; i--) {
        printf("%d ", s->a[i]);
    }
    printf("\n");
}
int main()
{
  int n,rem;
  struct stack s;
  s.top=-1;
  scanf("%d",&n);
  if(n<1)
  {
      printf("Number should be greater than 0.");
      return 0;
  }
  while(n!=0)
  {
      rem=n%2;
      push(&s,rem);
      n=n/2;
  }
  printStack(&s);
  while(!isEmpty(&s))
  {
      printf("%d",pop(&s));
  }
}

