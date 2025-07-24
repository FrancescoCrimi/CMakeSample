#include <iostream>
#include <vector>
#include "cpplib.hpp"

int main()
{
    try
    {
        // Crea istanze delle classi
        Num calculator;
        Str stringer("Hello, ");

        // Utilizza la classe Num
        int a = 10, b = 15;
        int result = calculator.sum(a, b);
        std::cout << "The sum of " << a << " and " << b << " is " << result << ".\n";

        std::vector<int> numbers = {1, 2, 3, 4, 5};
        std::string avg = array_to_string(numbers);
        std::cout << "The average between \"" << avg << "\" is " << calculator.average(numbers) << std::endl;

        // Utilizza la classe Str
        std::cout << "The prefix is " << stringer.getPrefix() << std::endl;
        std::cout << stringer.greet("Alice") << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    return 0;
}
