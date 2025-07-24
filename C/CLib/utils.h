#ifndef UTILS_H
#define UTILS_H

#include "clib_export.h" // Gestione di dllexport/dllimport
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Copia il contenuto di un array di interi su una stringa
     *
     * @param arr Array di numeri interi.
     * @param size Numero di elementi nell'array.
     * @param buffer buffer per il ritorno della stringa
     * @param buffer_size dimensione del buffer precedente
     */
    CLIB_API void array_to_string(const int *arr,
                                     size_t size,
                                     char *buffer,
                                     size_t buffer_size);

#ifdef __cplusplus
}
#endif

#endif // UTILS_H
