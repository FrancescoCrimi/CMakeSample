#include "Str.hpp"
#include <iostream>

// Implementazione del costruttore che inizializza el membro m_prefix con il valore passato.
Str::Str(const std::string &prefix)
    : m_prefix(prefix)
{
    if (prefix.empty())
    {
        throw std::invalid_argument("Il prefisso non può essere vuoto.");
    }
}

// Implementazione del metodo greet che utilizza il prefisso per restituire un saluto personalizzato.
std::string Str::greet(const std::string &name)
{
    return m_prefix + name + "!";
}

// Implementazione del metodo che restituisce il prefisso attuale.
std::string Str::getPrefix() const
{
    return m_prefix;
}