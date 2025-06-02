#include "database_manager.h"
#include <stdio.h>

int open_database(const char *db_name, sqlite3 **db)
{
    if (sqlite3_open(db_name, db) != SQLITE_OK)
    {
        fprintf(stderr, "Errore nell'apertura del database: %s\n", sqlite3_errmsg(*db));
        return 1;
    }
    printf("Database '%s' aperto con successo.\n", db_name);
    return 0;
}

void close_database(sqlite3 *db)
{
    sqlite3_close(db);
    printf("Database chiuso.\n");
}

int create_table(sqlite3 *db)
{
    const char *sql = "CREATE TABLE IF NOT EXISTS Users ("
                      "Id INTEGER PRIMARY KEY, "
                      "Name TEXT NOT NULL);";
    char *err_msg = NULL;

    if (sqlite3_exec(db, sql, NULL, NULL, &err_msg) != SQLITE_OK)
    {
        fprintf(stderr, "Errore nella creazione della tabella: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }
    printf("Tabella 'Users' creata o già esistente.\n");
    return 0;
}

int insert_data(sqlite3 *db, const char *name)
{
    const char *sql = "INSERT INTO Users (Name) VALUES (?);";
    sqlite3_stmt *stmt = NULL;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_DONE)
        {
            printf("Inserito utente: %s\n", name);
        }
        else
        {
            fprintf(stderr, "Errore nell'inserimento dei dati.\n");
            sqlite3_finalize(stmt);
            return 1;
        }

        sqlite3_finalize(stmt);
    }
    else
    {
        fprintf(stderr, "Errore nella preparazione della query.\n");
        return 1;
    }
    return 0;
}

int read_data(sqlite3 *db)
{
    const char *sql = "SELECT Id, Name FROM Users;";
    sqlite3_stmt *stmt = NULL;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
    {
        printf("Utenti presenti nel database:\n");
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int id = sqlite3_column_int(stmt, 0);
            const char *name = (const char *)sqlite3_column_text(stmt, 1);
            printf("Id: %d, Nome: %s\n", id, name);
        }
        sqlite3_finalize(stmt);
    }
    else
    {
        fprintf(stderr, "Errore nella preparazione della query.\n");
        return 1;
    }
    return 0;
}
