#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>
#include <exception>

int main()
{
    try
    {
        // Apertura (o creazione) del database "example.db".
        // Viene aperta in modalità lettura/scrittura; se non esiste, viene creato.
        SQLite::Database db("example.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        // Elimina la tabella se esiste, in modo da avere sempre uno stato iniziale.
        db.exec("DROP TABLE IF EXISTS Person");

        // Crea la tabella Person con tre colonne:
        // Id: intero con chiave primaria, Name: testo, Age: intero
        db.exec("CREATE TABLE Person (Id INTEGER PRIMARY KEY, Name TEXT, Age INTEGER)");

        // Inserisce alcuni record di esempio.
        {
            // Utilizziamo un'istruzione parametrizzata per l'inserimento.
            SQLite::Statement insert(db, "INSERT INTO Person (Name, Age) VALUES (?, ?)");

            // Inserimento del primo record.
            insert.bind(1, "Alice");
            insert.bind(2, 30);
            insert.exec();

            // Inserimento del secondo record.
            insert.reset();
            insert.bind(1, "Bob");
            insert.bind(2, 25);
            insert.exec();
        }

        // Esegue una query per selezionare tutti i record dalla tabella.
        SQLite::Statement query(db, "SELECT Id, Name, Age FROM Person");

        std::cout << "Dati presenti nella tabella Person:" << std::endl;

        // Cicla sui risultati della query e li stampa.
        while (query.executeStep())
        {
            int id = query.getColumn(0).getInt();
            std::string name = query.getColumn(1).getString();
            int age = query.getColumn(2).getInt();

            std::cout << "Id: " << id
                      << " | Name: " << name
                      << " | Age: " << age << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Eccezione: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
