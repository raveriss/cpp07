/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:33:32 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/07 17:18:54 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la bibliothèque standard pour l'utilisation de cout cin */
#include <iostream>

/* Inclusion de la bibliothèque std pour l'utilisation de rand srand */
#include <cstdlib>

/* Inclusion de la bibliothèque std pour l'utilisation de time */
#include <ctime>

/* Inclusion de la classe Array */
#include <../incs/Array.hpp>

/* Inclusion de la bibliothèque standard pour std::ostringstream */
#include <sstream>

/**
 * @brief Inclusion de la bibliothèque standard pour std::strcmp
 *        Utilisé pour comparer des chaînes de caractères C-style.
 */
#include <cstring>

/* Definitions of the maximum value for the array */
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

void captureAndCompareOutput(void (*func)(), const std::string& expected, const std::string& message)
{
    std::ostringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    
    func();
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expected, message);
}

void testInvalidIndexNegative()
{
    try
    {
        Array<int> numbers(MAX_VAL);
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void testInvalidIndexOverflow()
{
    try {
        Array<int> numbers(MAX_VAL);
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void printNewValues(Array<int>& numbers)
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
}

void captureAndCompareNewValues(Array<int>& numbers, const std::string& expected, const std::string& message)
{
    std::ostringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    
    printNewValues(numbers);
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expected, message);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
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

	else if (argc == 2 && strcmp(argv[1], "tester") == 0)
    {
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
		std::cout << CYAN << "/*                                 OPTIONNEL                                  */" << NC << std ::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;

        std::cout << MAGENTA << "TEST EMPTY ARRAY" << NC << std::endl;

        Array<int> emptyArray;
        ASSERT_TEST(emptyArray.size() == 0, "Empty array should have size 0");

        std::cout << std::endl << MAGENTA << "TEST ARRAY SIZE" << NC << std::endl;
        Array<int> array(MAX_VAL);
        ASSERT_TEST(array.size() == MAX_VAL, "Array should have the specified size");

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
        
        std::cout << MAGENTA << std::endl << "TEST THAT THE VALUES ​​AFTER COPYING ARE INTACT" << NC << std::endl;
        std::cout << YELLOW << "Initial values:" << NC << std::endl;

        /* display only the first 10 for brevity */
        for (int i = 0; i < 10; i++)
        {
            std::cout << "numbers[" << i << "] = " << numbers[i] << "\nmirror[" << i << "] = " << mirror[i] << std::endl << std::endl;
        }
        
        /* SCOPE */
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

        /* Initial values */
        std::cout << YELLOW << "New values after reassignment:" << NC << std::endl;

        /* display only the first 10 for brevity */
        for (int i = 0; i < 10; i++)
        {
            std::cout << "numbers[" << i << "] = " << numbers[i] << "\nmirror[" << i << "] = " << mirror[i] << std::endl;
        }
        captureAndCompareNewValues(numbers, newValuesExpected.str(), "New values after reassignment");

        delete [] mirror;
    }

	else
	{
		std::cout << RED << "Usage: ./array or ./array tester" << NC << std::endl;
		return 1;
	}
    
    return 0;
}

/* main.cpp */
