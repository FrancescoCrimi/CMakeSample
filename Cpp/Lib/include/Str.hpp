#ifndef STR_H
#define STR_H

#include "export.hpp"
#include <string>

// Classe che rappresenta un oggetto con un nome
class MYLIBCPP_API Str
{
public:
    // Costruttore che accetta un parametro stringa (ad esempio, un prefisso per il saluto)
    explicit Str(const std::string &prefix);

    // Metodo che restituisce un saluto personalizzato.
    // Ad esempio, se il prefisso è "Hello, " allora greet("Alice") restituisce "Hello, Alice!"
    std::string greet(const std::string &name);

    // Metodo che restituisce il prefisso attuale memorizzato nella classe.
    std::string getPrefix() const;

private:
    // Variabile membro che contiene il nome
    std::string m_prefix;
};

#endif // STR_H
