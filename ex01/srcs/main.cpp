/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:00:00 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/31 13:52:19 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe ScalarConverter */
#include "../incs/ScalarConverter.hpp"

/* Inclusion de la bibliothèque standard pour l'utilisation de flux d'entrée/sortie standard */
#include <iostream>

/* Inclusion de la bibliothèque standard pour std::ostringstream */
#include <sstream>

/* Inclusion de la bibliothèque standard pour std::string */
#include <cstring>

/* Inclusion de la bibliothèque standard pour pour INT_MIN, INT_MAX */
#include <climits>

/* Inclusion de la bibliothèque standard pour les limites des types flottants */
#include <cfloat>

/* Inclusion de la bibliothèque standard pour obtenir les limites des types numériques */
#include <limits>

/* Inclusion de la bibliothèque standard pour std::fixed, std::setprecision */
#include <iomanip>

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

/**
 *  @brief Macro for asserting test results and displaying appropriate messages
 */
#define ASSERT_TEST(expression, message) \
	if (expression) { std::cout << "\033[32m[TEST PASSED]\033[0m " << message << std::endl; } \
	else { std::cout << "\033[31m[TEST FAILED]\033[0m " << message << std::endl; }

/**
 * @brief Teste la conversion d'une chaîne de caractères et compare le résultat attendu
 */
void testConversion(const std::string& input, const std::string& expectedOutput) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    ScalarConverter::convert(input);
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expectedOutput, "Input: " + input + "\n" + output);
}

/**
 * @brief Converts a numeric value to a string using std::ostringstream
 */
template<typename T>
std::string toString(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

/**
 * @brief Specialization of toString for float type
 */
template<>
std::string toString<float>(float value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << value;
    return oss.str();
}

/**
 * @brief Specialization of toString for double type
 */
template<>
std::string toString<double>(double value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << value;
    return oss.str();
}

/**
 *  @brief Point d'entrée principal du programme
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>\n";
        return 1;
    }
    
    /**
     * Tester
     */
    if (strcmp(argv[1], "tester") == 0)
    {
        /**
         * MANDATORY TESTS
         */
        std::cout << std::endl << CYAN << "MANDATORY TESTS:" << NC << std::endl;

        testConversion("0", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");
        testConversion("nan", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
        testConversion("42.0f", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");

        /**
         * ADDITIONAL TESTS
         */
        std::cout << CYAN << "ADDITIONAL TESTS:" << NC << std::endl;

        /* Test cases for char conversions */
        testConversion("a", "char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0\n");
        testConversion("z", "char: 'z'\nint: 122\nfloat: 122.0f\ndouble: 122.0\n");

        /* Test cases for int conversions */
        testConversion("42", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
        testConversion("-42", "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n");

        /* Test cases for float conversions */
        testConversion("-42.0f", "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n");
        testConversion("nanf", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
        testConversion("+inff", "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n");
        testConversion("-inff", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n");

        /* Test cases for double conversions */
        testConversion("42.0", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
        testConversion("-42.0", "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n");
        testConversion("+inf", "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n");
        testConversion("-inf", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n");

        /* Test cases for impossible conversions */
        testConversion("hello", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
        testConversion("42.0a", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");

        std::cout << CYAN << "ADDITIONAL SUGGESTED TESTS:\n" << NC << std::endl;

        /* Test cases for INT_MIN, INT_MAX, FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX */
        std::cout << CYAN << "INT_MIN: " << INT_MIN << NC << std::endl;
        testConversion(toString(INT_MIN), "char: impossible\nint: " + toString(INT_MIN) + "\nfloat: " + toString(static_cast<float>(INT_MIN)) + "f\ndouble: " + toString(static_cast<double>(INT_MIN)) + "\n");
        
        std::cout << CYAN << "INT_MAX: " << INT_MAX << NC << std::endl;
        testConversion(toString(INT_MAX), "char: impossible\nint: " + toString(INT_MAX) + "\nfloat: " + toString(static_cast<float>(INT_MAX)) + "f\ndouble: " + toString(static_cast<double>(INT_MAX)) + "\n");

        std::cout << CYAN << "FLT_MIN: " << FLT_MIN << NC << std::endl;
        testConversion(toString(FLT_MIN), "char: Non displayable\nint: 0\nfloat: " + toString(FLT_MIN) + "f\ndouble: " + toString(static_cast<double>(FLT_MIN)) + "\n");
        
        std::cout << CYAN << "FLT_MAX: " << FLT_MAX << NC << std::endl;
        testConversion(toString(FLT_MAX), "char: impossible\nint: impossible\nfloat: " + toString(FLT_MAX) + "f\ndouble: " + toString(static_cast<double>(FLT_MAX)) + "\n");

        std::cout << CYAN << "DBL_MIN: " << DBL_MIN << NC << std::endl;
        testConversion(toString(DBL_MIN), "char: Non displayable\nint: 0\nfloat: " + toString(static_cast<float>(DBL_MIN)) + "f\ndouble: " + toString(DBL_MIN) + "\n");
        
        std::cout << CYAN << "DBL_MAX: " << DBL_MAX << NC << std::endl;
        testConversion(toString(DBL_MAX), "char: impossible\nint: impossible\nfloat: +" + toString(static_cast<float>(DBL_MAX)) + "f\ndouble: " + toString(DBL_MAX) + "\n");

        /* Test case for positive negative floating point digit 0 */
        std::cout << CYAN << "-0.0: " << NC << std::endl;
        testConversion("-0.0", "char: Non displayable\nint: 0\nfloat: -0.0f\ndouble: -0.0\n");

        std::cout << CYAN << "+0.0: " << NC << std::endl;
        testConversion("+0.0", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");


        /* Test cases for hexadecimal numbers */
        std::cout << CYAN << "0x1A: " << NC << std::endl;
        testConversion("0x1A", "char: Non displayable\nint: 26\nfloat: 26.0f\ndouble: 26.0\n");

        /* Test cases for exponential numbers */
        std::cout << CYAN << "1e10: " << NC << std::endl;
        testConversion("1e10", "char: impossible\nint: impossible\nfloat: 10000000000.0f\ndouble: 10000000000.0\n");

        std::cout << CYAN << "2.5e-3: " << NC << std::endl;
        testConversion("2.5e-3", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");
   
        /* Test case for caracter impossible */
        std::cout << CYAN << "CARACTERE IMPOSSIBLE: " << NC << std::endl;
        std::cout << CYAN << "123abc: " << NC << std::endl;
        testConversion("123abc", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");

        std::cout << CYAN << "!@#$%: " << NC << std::endl;
        testConversion("!@#$%", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
        
        return 0;

    }
    
    ScalarConverter::convert(argv[1]);

    return 0;
}

/* main.cpp */