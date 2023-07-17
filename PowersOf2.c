#include <stdio.h>

void powers(int a)
{
    int power = 1;
    // iterate a times
    for (int i = 0; i <=5 a; i++)
    {
        // print current power of 2
        printf("%d ", power); 
        // calculate next power of 2      
        power= power* 2;                 
    }

    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of powers of 2 to print: ");
    scanf("%d", &n);

    powers(n);
    
    return 0;
}
