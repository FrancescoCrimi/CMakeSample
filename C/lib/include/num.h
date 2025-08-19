#ifndef NUM_H
#define NUM_H

#include <stddef.h>         // Aggiunto per definizione di size_t
#include "export.h"         // Gestione di dllexport/dllimport

#ifdef __cplusplus
extern "C"
{
#endif

    // Funzione che somma due numeri interi e restituisce il risultato.
    MYLIBC_API int sum(int a, int b);

    /**
     * Calcola la media di un array di numeri interi.
     * Se la dimensione dell'array è 0, restituisce 0.0 per evitare errori di divisione.
     *
     * @param numbers Array di numeri interi.
     * @param size Numero di elementi nell'array.
     * @return La media degli elementi dell'array (double).
     */
    MYLIBC_API double average(const int *numbers, size_t size);

#ifdef __cplusplus
}
#endif

#endif // NUM_H
