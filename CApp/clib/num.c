#include "num.h"

// Funzione che somma due interi.
// Ritorna la somma di a e b.
int sum(int a, int b)
{
    return a + b;
}

// Funzione che calcola la media di un array di interi.
// Se l'array è vuoto (size == 0), ritorna 0.0 per evitare errori di divisione.
double average(const int *numbers, size_t size)
{
    if (size == 0)
    {
        return 0.0; // Evita la divisione per zero.
    }

    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += numbers[i];
    }

    return (double)sum / size; // Conversione esplicita a double per ottenere la media corretta.
}
