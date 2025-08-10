#include "mylibc.h" // Header aggregato della libreria
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Utilizza la funzione di somma
    int x = 3, y = 5;
    int s = sum(x, y);
    printf("The sum of %d and %d is %d\n", x, y, s);

    int numbers[] = {1, 3, 5, 7, 9};
    size_t count = sizeof(numbers) / sizeof(numbers[0]);

    /**
     * Buffer per la stringa finale.
     * non è necessario liberarla manualmente perchè
     * allocata staticamente nello stack
     * verrà automaticamente deallocata quando la funzione termina
     * o quando la variabile esce dal suo scope.
     */
    char result[100];
    array_to_string(numbers, count, result, sizeof(result));

    // Usa la funzione average per calcolare la media
    double avg = average(numbers, count);
    printf("The average between %s is %.2f\n", result, avg);

    // Utilizza la funzione per le stringhe
    char *greeting = greet("Alice");
    if (greeting != NULL)
    {
        printf("Greeting: %s\n", greeting);
        free(greeting); // Libera la memoria allocata dalla funzione greet
    }

    return 0;
}
