#include "Utils.hpp"
#include <iostream>
#include <sstream>

std::string array_to_string(const std::vector<int> &arr)
{
    if (arr.empty())
        return ""; // Ritorna stringa vuota se il vettore è vuoto.

    std::ostringstream oss;
    for (int num : arr)
    {
        oss << num << " ";
    }

    std::string result = oss.str();
    result.pop_back(); // Rimuove lo spazio finale

    return result;
}