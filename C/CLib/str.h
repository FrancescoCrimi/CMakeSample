#ifndef STR_H
#define STR_H

#include "clib_export.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Restituisce un saluto personalizzato formato "Hi, <name>!".
     * La funzione alloca dinamicamente la stringa con malloc;
     * Il chiamante è responsabile di liberare la memoria allocata.
     */
    CLIB_API char *greet(const char *name);

#ifdef __cplusplus
}
#endif

#endif // STR_H
