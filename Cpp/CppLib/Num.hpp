#ifndef NUM_H
#define NUM_H

#include "cpplib_export.hpp"
#include <vector>

// La classe Num fornisce metodi per operazioni numeriche
class CPPLIB_API Num
{
public:
    // Metodo che ritorna la somma di due numeri interi
    int sum(int a, int b);

    /**
     * Calcola la media degli elementi in un vettore di interi.
     * Se il vettore è vuoto, ritorna 0.0 per evitare una divisione per zero.
     *
     * @param nums Il vettore di numeri interi.
     * @return La media (double) degli elementi del vettore.
     */
    double average(const std::vector<int> &nums) const;
};

#endif // NUM_H