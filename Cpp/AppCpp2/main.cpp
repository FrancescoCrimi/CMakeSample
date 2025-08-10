#include <iostream>
#include <vector>
#include "MyLibCpp.hpp"

int main()
{
    try
    {
        // Crea istanze delle classi
        Num calculator;
        Str stringer("Ciao, ");

        // Utilizza la classe Num
        int a = 3, b = 7;
        int result = calculator.sum(a, b);
        std::cout << "The sum of " << a << " and " << b << " is " << result << ".\n";

        std::vector<int> numbers = {1, 3, 5, 7, 9};
        std::string avg = array_to_string(numbers);
        std::cout << "The average between \"" << avg << "\" is " << calculator.average(numbers) << std::endl;

        // Utilizza la classe Str
        std::cout << "The prefix is " << stringer.getPrefix() << std::endl;
        std::cout << stringer.greet("Bob") << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    return 0;
}
