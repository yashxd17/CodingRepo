#include <stdio.h>
#include <stdlib.h>

int main() {
    int seed = rand(); // Use random number as seed
    srand(seed);
    int number = rand() % 10 + 1; // Generate random number between 1 and 10
    int ch, attempts = 0;
    printf("Guess the number between 1 and 10: ");
    do {
        scanf("%d", &ch);
        attempts++;
        if (ch < number) printf("Too low! Guess again: ");
        else if (ch > number) printf("Too high! Guess again: ");
    } while (ch != number);
    printf("Congratulations, you guessed the number in %d attempts!", attempts);
    return 0;
}