/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:11:22 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/07 17:57:06 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la fonction template iter */
#include "../incs/Iter.hpp"

/* Inclusion de la bibliothèque standard pour l'utilisation de flux d'entrée/sortie standard */
#include <iostream>

/* Inclusion de la bibliothèque standard pour l'utilisation de std::numeric_limits */
#include <limits>

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

/**
 * @brief Template function to print an element
 */
template <typename T>
void printElement(T &element) {
    std::cout << element << std::endl;
}

/**
 * @brief Template function to increment an element
 */
template <typename T>
void increment(T &element) {
    ++element;
}

/**
 * @brief Template function to test iter function
 */
template <typename T>
void testIter(T *array, int length, void (*func)(T &), T *expectedArray) {
    iter(array, length, func);
    bool passed = true;
    for (int i = 0; i < length; ++i) {
        if (array[i] != expectedArray[i]) {
            passed = false;
            break;
        }
    }
    ASSERT_TEST(passed, "iter function works correctly.");
}

/**
 * @brief Main function
 */
int main(int argc, char *argv[])
{
    (void)argv;
    if (argc == 1)
    {
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
        std::cout << CYAN << "/*                                    CHAR                                    */" << NC << std::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;

        std::cout << MAGENTA << "TEST WITH CHAR" << NC << std::endl;

        /* Test iter with characters */
        char charArray[] = {'a', 'b', 'c', 'd', 'e'};
        char charArrayExpected[] = {'b', 'c', 'd', 'e', 'f'};
        testIter(charArray, 5, increment, charArrayExpected);

        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
        std::cout << CYAN << "/*                                   INTEGERS                                 */" << NC << std::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;

        std::cout << MAGENTA << "TEST WITH ORDINARY INTEGER" << NC << std::endl;

        int intArray[] = {0, 1, 2, 3, 4};
        int intArrayIncremented[] = {1, 2, 3, 4, 5};
        testIter(intArray, 5, increment, intArrayIncremented);

        std::cout << MAGENTA << "TEST WITH INT MAX" << NC << std::endl;

        long long int intMax = std::numeric_limits<int>::max();
        long long int intMaxIncremented = intMax + 1;
        long long int intArrayMax[] = {intMax};
        long long int intArrayMaxExpected[] = {intMaxIncremented};
        testIter(intArrayMax, 1, increment, intArrayMaxExpected);

        std::cout << MAGENTA << "TEST WITH INT MIN" << NC << std::endl;

        long long int intMin = std::numeric_limits<int>::min();
        long long int intMinIncremented = intMin + 1;
        long long int intArrayMin[] = {intMin};
        long long int intArrayMinExpected[] = {intMinIncremented};
        testIter(intArrayMin, 1, increment, intArrayMinExpected);

        std::cout << MAGENTA << "TEST WITH INT MAX + 1" << NC << std::endl;

        long long int intMaxPlusOne = static_cast<long long>(std::numeric_limits<int>::max()) + 1;
        long long int intMaxPlusOneIncremented = intMaxPlusOne + 1;
        long long int intArrayMaxPlusOne[] = {intMaxPlusOne};
        long long int intArrayMaxPlusOneExpected[] = {intMaxPlusOneIncremented};
        testIter(intArrayMaxPlusOne, 1, increment, intArrayMaxPlusOneExpected);

        std::cout << MAGENTA << "TEST WITH INT MIN - 1" << NC << std::endl;

        long long int intMinMinusOne = static_cast<long long>(std::numeric_limits<int>::min()) - 1;
        long long int intMinMinusOneIncremented = intMinMinusOne + 1;
        long long int intArrayMinMinusOne[] = {intMinMinusOne};
        long long int intArrayMinMinusOneExpected[] = {intMinMinusOneIncremented};
        testIter(intArrayMinMinusOne, 1, increment, intArrayMinMinusOneExpected);

        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
        std::cout << CYAN << "/*                                    FLOAT                                   */" << NC << std::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;
        
        /* Test iter with ordinary floats */
        std::cout << MAGENTA << "TEST WITH FLOAT ORDINARY" << NC << std::endl;
        float floatArray[] = {0.1f, 1.1f, 2.1f, 3.1f, 4.1f};
        float floatArrayIncremented[] = {1.1f, 2.1f, 3.1f, 4.1f, 5.1f};
        testIter(floatArray, 5, increment, floatArrayIncremented);

        /* Test iter with float max */
        std::cout << MAGENTA << "TEST WITH FLOAT MAX" << NC << std::endl;
        float floatMax = std::numeric_limits<float>::max();
        float floatMaxIncremented = floatMax + 1.0f;
        float floatArrayMax[] = {floatMax};
        float floatArrayMaxExpected[] = {floatMaxIncremented};
        testIter(floatArrayMax, 1, increment, floatArrayMaxExpected);

        /* Test iter with float min */
        std::cout << MAGENTA << "TEST WITH FLOAT MIN" << NC << std::endl;
        float floatMin = std::numeric_limits<float>::min();
        float floatMinIncremented = floatMin + 1.0f;
        float floatArrayMin[] = {floatMin};
        float floatArrayMinExpected[] = {floatMinIncremented};
        testIter(floatArrayMin, 1, increment, floatArrayMinExpected);

        /* Test iter with float max + 1 */
        std::cout << MAGENTA << "TEST WITH FLOAT MAX + 1" << NC << std::endl;
        float floatMaxPlusOne = std::numeric_limits<float>::max() + 1.0f;
        float floatMaxPlusOneIncremented = floatMaxPlusOne + 1.0f;
        float floatArrayMaxPlusOne[] = {floatMaxPlusOne};
        float floatArrayMaxPlusOneExpected[] = {floatMaxPlusOneIncremented};
        testIter(floatArrayMaxPlusOne, 1, increment, floatArrayMaxPlusOneExpected);

        /* Test iter with float min - 1 */
        std::cout << MAGENTA << "TEST WITH FLOAT MIN - 1" << NC << std::endl;
        float floatMinMinusOne = std::numeric_limits<float>::min() - 1.0f;
        float floatMinMinusOneIncremented = floatMinMinusOne + 1.0f;
        float floatArrayMinMinusOne[] = {floatMinMinusOne};
        float floatArrayMinMinusOneExpected[] = {floatMinMinusOneIncremented};
        testIter(floatArrayMinMinusOne, 1, increment, floatArrayMinMinusOneExpected);

        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
        std::cout << CYAN << "/*                                    DOUBLE                                  */" << NC << std::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;

        std::cout << MAGENTA << "TEST WITH DOUBLE ORDINARY" << NC << std::endl;

        /* Test iter with doubles */
        double doubleArray[] = {0.1, 1.1, 2.1, 3.1, 4.1};
        double doubleArrayIncremented[] = {1.1, 2.1, 3.1, 4.1, 5.1};
        testIter(doubleArray, 5, increment, doubleArrayIncremented);

        /* Test iter with double max */
        std::cout << MAGENTA << "TEST WITH DOUBLE MAX" << NC << std::endl;
        double doubleMax = std::numeric_limits<double>::max();
        double doubleMaxIncremented = doubleMax + 1.0;
        double doubleArrayMax[] = {doubleMax};
        double doubleArrayMaxExpected[] = {doubleMaxIncremented};
        testIter(doubleArrayMax, 1, increment, doubleArrayMaxExpected);

        /* Test iter with double min */
        std::cout << MAGENTA << "TEST WITH DOUBLE MIN" << NC << std::endl;
        double doubleMin = std::numeric_limits<double>::min();
        double doubleMinIncremented = doubleMin + 1.0;
        double doubleArrayMin[] = {doubleMin};
        double doubleArrayMinExpected[] = {doubleMinIncremented};
        testIter(doubleArrayMin, 1, increment, doubleArrayMinExpected);

        /* Test iter with double max + 1 */
        std::cout << MAGENTA << "TEST WITH DOUBLE MAX + 1" << NC << std::endl;
        double doubleMaxPlusOne = std::numeric_limits<double>::max() + 1.0;
        double doubleMaxPlusOneIncremented = doubleMaxPlusOne + 1.0;
        double doubleArrayMaxPlusOne[] = {doubleMaxPlusOne};
        double doubleArrayMaxPlusOneExpected[] = {doubleMaxPlusOneIncremented};
        testIter(doubleArrayMaxPlusOne, 1, increment, doubleArrayMaxPlusOneExpected);

        /* Test iter with double min - 1 */
        std::cout << MAGENTA << "TEST WITH DOUBLE MIN - 1" << NC << std::endl;
        double doubleMinMinusOne = std::numeric_limits<double>::min() - 1.0;
        double doubleMinMinusOneIncremented = doubleMinMinusOne + 1.0;
        double doubleArrayMinMinusOne[] = {doubleMinMinusOne};
        double doubleArrayMinMinusOneExpected[] = {doubleMinMinusOneIncremented};
        testIter(doubleArrayMinMinusOne, 1, increment, doubleArrayMinMinusOneExpected);

        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
        std::cout << CYAN << "/*                                    STRING                                  */" << NC << std::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;
        
        /* Test iter with strings */
        std::string strArray[] = {"Hello", "World", "42", "School"};
        std::string strArrayExpected[] = {"Hello", "World", "42", "School"};
        
        iter(strArray, 4, printElement);
        ASSERT_TEST(true, "Print elements of string array");
    }

	else
	{
		std::cout << RED << "Usage: ./iter" << NC << std::endl;
		return 1;
	}

    return 0;
}

/* main.cpp */
