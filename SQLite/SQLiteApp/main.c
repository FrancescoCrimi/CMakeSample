#include "database_manager.h"
#include <stdio.h>

int main()
{
    sqlite3 *db = NULL;

    // Apri il database
    if (open_database("example.db", &db) != 0)
    {
        return 1;
    }

    // Crea la tabella
    if (create_table(db) != 0)
    {
        close_database(db);
        return 1;
    }

    // Inserisci dati
    if (insert_data(db, "Alice") != 0 || insert_data(db, "Bob") != 0)
    {
        close_database(db);
        return 1;
    }

    // Leggi i dati
    if (read_data(db) != 0)
    {
        close_database(db);
        return 1;
    }

    // Chiudi il database
    close_database(db);
    return 0;
}
