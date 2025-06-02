#include "utils.h"
#include <stdio.h>

void array_to_string(const int *arr, size_t size, char *buffer, size_t buffer_size)
{
    if (size == 0)
    {
        snprintf(buffer, buffer_size, ""); // Stringa vuota se l'array è vuoto.
        return;
    }

    size_t offset = 0;
    for (size_t i = 0; i < size; i++)
    {
        offset += snprintf(buffer + offset, buffer_size - offset, "%d ", arr[i]);
        if (offset >= buffer_size)
            break; // Evita di superare la dimensione del buffer.
    }

    buffer[offset - 1] = '\0'; // Rimuove lo spazio finale e chiude la stringa.
}