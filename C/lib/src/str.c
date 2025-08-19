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
        strncpy(greeting, prefix, len);
        greeting[strlen(prefix)] = '\0';
        strncat(greeting, name, len - strlen(greeting) - 1);
    }
    return greeting;
}

void free_greet(char *greeting)
{
    free(greeting);
}