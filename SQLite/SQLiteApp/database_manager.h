#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <sqlite3.h>

// Dichiarazione delle funzioni
int open_database(const char *db_name, sqlite3 **db);
void close_database(sqlite3 *db);
int create_table(sqlite3 *db);
int insert_data(sqlite3 *db, const char *name);
int read_data(sqlite3 *db);

#endif // DATABASE_MANAGER_H
