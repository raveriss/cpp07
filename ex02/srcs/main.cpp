#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Array.hpp>
#include <sstream>

#define MAX_VAL 750

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

/* Macro for asserting test results and displaying appropriate messages */
#define ASSERT_TEST(expression, message) \
    if (expression) { std::cout << GREEN "[TEST PASSED]" << NC << " " << message << std::endl; } \
    else { std::cout << RED "[TEST FAILED]" << NC << " " << message << std::endl; }

void captureAndCompareOutput(void (*func)(), const std::string& expected, const std::string& message) {
    std::ostringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    
    func();
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expected, message);
}

void testInvalidIndexNegative() {
    try {
        Array<int> numbers(MAX_VAL);
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testInvalidIndexOverflow() {
    try {
        Array<int> numbers(MAX_VAL);
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void printNewValues(Array<int>& numbers) {
    for (int i = 0; i < 10; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
}

void captureAndCompareNewValues(Array<int>& numbers, const std::string& expected, const std::string& message) {
    std::ostringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    
    printNewValues(numbers);
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expected, message);
}

int main(int, char**)
{
    {
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
		std::cout << CYAN << "/*                                 MANDATORY                                  */" << NC << std ::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;

        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;
    }

    {

		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
		std::cout << CYAN << "/*                                 OPTIONNEL                                  */" << NC << std ::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;

        /* Instanciation template Array<int> avec taille MAX_VAL */
        Array<int> numbers(MAX_VAL);

        /* Instanciation tableau miroir */
        int* mirror = new int[MAX_VAL];

        /* Initialisation des valeurs aléatoires */
        srand(time(NULL));
        
        /* Assigner les valeurs aléatoires aux deux tableaux */
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        
        std::cout << MAGENTA << "TEST THAT THE VALUES ​​AFTER COPYING ARE INTACT" << NC << std::endl;
        std::cout << YELLOW << "Initial values:" << NC << std::endl;

        /* display only the first 10 for brevity */
        for (int i = 0; i < 10; i++)
        {
            std::cout << "numbers[" << i << "] = " << numbers[i] << "\nmirror[" << i << "] = " << mirror[i] << std::endl << std::endl;
        }
        
        // SCOPE
        {
            /* Copy constructor */
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        /* Check values after copying */
        bool valuesIntact = true;
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                valuesIntact = false;
                break;
            }
        }
        ASSERT_TEST(valuesIntact, "Values after copying are intact");

        std::cout << std::endl;

        /* Exception handling tests */
        std::cout << MAGENTA << "TEST NEGATIVE INDEX EXCEPTION HANDLING" << NC << std::endl;

        captureAndCompareOutput(testInvalidIndexNegative, "Index out of range\n", "Exception for negative index");
        
        std::cout << std::endl;

        std::cout << MAGENTA << "TEST OVERFLOW INDEX EXCEPTION HANDLING" << NC << std::endl;
        captureAndCompareOutput(testInvalidIndexOverflow, "Index out of range\n", "Exception for overflow index");

        std::cout << std::endl;

        /* Reassigning new random values */
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        
        std::ostringstream newValuesExpected;
        for (int i = 0; i < 10; i++) {
            newValuesExpected << "numbers[" << i << "] = " << numbers[i] << std::endl;
        }

        std::cout << MAGENTA << "TEST REASSIGNMENT" << NC << std::endl;

        // Initial values
        std::cout << YELLOW << "New values after reassignment:" << NC << std::endl;

        /* display only the first 10 for brevity */
        for (int i = 0; i < 10; i++)
        {
            std::cout << "numbers[" << i << "] = " << numbers[i] << "\nmirror[" << i << "] = " << mirror[i] << std::endl;
        }
        captureAndCompareNewValues(numbers, newValuesExpected.str(), "New values after reassignment");

        delete [] mirror;
    }
    return 0;
}
