#ifndef STR_H
#define STR_H

#include "export.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Restituisce un saluto personalizzato formato "Hi, <name>!".
     * La funzione alloca dinamicamente la stringa con malloc;
     * Il chiamante è responsabile di liberare la memoria allocata.
     */
    MYLIBC_API char *greet(const char *name);

    /**
     * Libera la memoria allocata da greet().
     * È consigliato usare questa funzione invece di free().
     */
    MYLIBC_API void free_greet(char *greeting);

#ifdef __cplusplus
}
#endif

#endif // STR_H
