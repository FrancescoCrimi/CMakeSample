#include "Num.hpp"

// Implementazione del metodo statico per sommare due numeri
int Num::sum(int a, int b)
{
    return a + b;
}

// Implementazione del metodo statico per calcolare la media
double Num::average(const std::vector<int> &nums) const
{
    if (nums.empty())
    {
        return 0.0; // Ritorna 0.0 se il vettore è vuoto per evitare la divisione per zero.
    }

    int total = 0;
    for (int n : nums)
    {
        total += n;
    }
    return static_cast<double>(total) / nums.size();
}
