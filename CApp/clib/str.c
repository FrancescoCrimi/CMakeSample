#include "str.h"
#include <stdlib.h>
#include <string.h>

char *greet(const char *name)
{
    const char *prefix = "Ciao ";
    size_t len = strlen(prefix) + strlen(name) + 1; // +1 per il terminatore

    /**
     * Buffer allocato dinamicamente da deallocare
     * manualmente con free()
     */
    char *greeting = (char *)malloc(len);
    if (greeting != NULL)
    {
        strcpy_s(greeting, len, prefix);
        strcat_s(greeting, len, name);
    }
    return greeting;
}
