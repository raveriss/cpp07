/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:33:41 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/04 03:52:00 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <string>
#include <sstream>
#include <limits>
#include <cstring>

/* Inclure les fonctions de la classe Whatever */
#include "../incs/whatever.hpp"

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
	if (expression) { std::cout << GREEN << "[TEST PASSED]" << NC << " " << message << std::endl; } \
	else { std::cout << RED << "[TEST FAILED]" << NC << " " << message << std::endl; }

/**
 * @brief Convertit une valeur en chaîne de caractères
 */
template <typename T>
std::string toString(const T& value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

/**
 *  @brief Point d'entrée principal du programme
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << CYAN << "\n/* ************************************************************************** */" << NC << std ::endl;
		std::cout << CYAN << "/*                                 MANDATORY                                  */" << NC << std::endl;
		std::cout << CYAN << "/* ************************************************************************** */" << NC << std ::endl;
		
		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

		return 0;
	}
	
	/**
	 * Tester
	 */
	else if (argc == 2 && strcmp(argv[1], "tester") == 0)
	{
		std::cout << CYAN << "\n/* ************************************************************************** */" << NC << std ::endl;
		std::cout << CYAN << "/*                                 TESTER PART                                */" << NC << std::endl;
		std::cout << CYAN << "/* ************************************************************************** */\n" << NC << std ::endl;

		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
		std::cout << CYAN << "/*                                   INTEGERS                                 */" << NC << std ::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;

		std::cout << CYAN << "TEST WITH ORDINARY INTEGER" << NC << std::endl;

		/* Test swap with integers */
		int x = 1, y = 2;
		::swap(x, y);
		ASSERT_TEST(x == 2 && y == 1, "swap(int): x = " + toString(x) + ", y = " + toString(y));

		/* Test min with integers */ 
		ASSERT_TEST(::min(3, 4) == 3, "min(int): min(3, 4) == 3");
		
		/* Test max with integers */
		ASSERT_TEST(::max(3, 4) == 4, "max(int): max(3, 4) == 4");

		/* Test INT_MIN and INT_MAX */
		std::cout << CYAN << "\nTEST WITH INT_MIN AND INT_MAX" << NC << std::endl;

		/* Test swap INT_MIN and INT_MAX */
		int int_min = std::numeric_limits<int>::min();
		int int_max = std::numeric_limits<int>::max();
		::swap(int_min, int_max);
		ASSERT_TEST(int_min == std::numeric_limits<int>::max() && int_max == std::numeric_limits<int>::min(), 
					"swap(int): int_min = " + toString(int_min) + ", int_max = " + toString(int_max));
		
		ASSERT_TEST(::min(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) == std::numeric_limits<int>::min(), 
					"min(int): min(INT_MIN, INT_MAX) == INT_MIN");
		ASSERT_TEST(::max(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) == std::numeric_limits<int>::max(), 
					"max(int): max(INT_MIN, INT_MAX) == INT_MAX");

		std::cout << CYAN << "\nTEST WITH INT_MIN-1 AND INT_MAX+1" << NC << std::endl;
		/* Test min below INT_MIN and max above INT_MAX */
		long long int min_below = static_cast<long long int>(std::numeric_limits<int>::min()) - 1;
		long long int max_above = static_cast<long long int>(std::numeric_limits<int>::max()) + 1;
		ASSERT_TEST(::min(min_below, max_above) == min_below, 
					"min(long long): min(INT_MIN-1, INT_MAX+1) == INT_MIN-1");
		ASSERT_TEST(::max(min_below, max_above) == max_above, 
					"max(long long): max(INT_MIN-1, INT_MAX+1) == INT_MAX+1");

		/* Test swap INT_MIN-1 and INT_MAX+1 */
		::swap(min_below, max_above);
		ASSERT_TEST(min_below == static_cast<long long int>(std::numeric_limits<int>::max()) + 1 && max_above == static_cast<long long int>(std::numeric_limits<int>::min()) - 1, 
					"swap(long long): min_below = " + toString(min_below) + ", max_above = " + toString(max_above));
					
		std::cout << CYAN << "\n/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
		std::cout << CYAN << "/*                                    STRING                                  */" << NC << std ::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;
		
		/* Test swap with strings */
		std::string str1 = "hello", str2 = "world";
		::swap(str1, str2);
		ASSERT_TEST(str1 == "world" && str2 == "hello", "swap(string): str1 = " + str1 + ", str2 = " + str2);

		/* Test min with strings */
		ASSERT_TEST(::min(std::string("apple"), std::string("banana")) == "apple", "min(string): min('apple', 'banana') == 'apple'");

		/* Test max with strings */
		ASSERT_TEST(::max(std::string("apple"), std::string("banana")) == "banana", "max(string): max('apple', 'banana') == 'banana'");

		std::cout << CYAN << "\n/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
		std::cout << CYAN << "/*                                    FLOATS                                  */" << NC << std ::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;
		/* Test swap with float min and max */
        float float_min = std::numeric_limits<float>::min();
        float float_max = std::numeric_limits<float>::max();
        ::swap(float_min, float_max);
        ASSERT_TEST(float_min == std::numeric_limits<float>::max() && float_max == std::numeric_limits<float>::min(), 
                    "swap(float): float_min = " + toString(float_min) + ", float_max = " + toString(float_max));

		/* Test min and max with float */
		ASSERT_TEST(::min(3.14f, 2.71f) == 2.71f, "min(float): min(3.14f, 2.71f) == 2.71f");
		ASSERT_TEST(::max(3.14f, 2.71f) == 3.14f, "max(float): max(3.14f, 2.71f) == 3.14f");

		/* Test swap with float max + 1 and min - 1 */
        float float_min_1 = std::numeric_limits<float>::min() - 1;
        float float_max_1 = std::numeric_limits<float>::max() + 1;
        ::swap(float_min_1, float_max_1);
        ASSERT_TEST(float_min_1 == std::numeric_limits<float>::max() + 1 && float_max_1 == std::numeric_limits<float>::min() - 1, 
                    "swap(float): float_min_1 = " + toString(float_min_1) + ", float_max_1 = " + toString(float_max_1));

        /* Test swap with float -0.0 and +0.0 */
        float neg_zero = -0.01f, pos_zero = +0.01f;
        ::swap(neg_zero, pos_zero);
        ASSERT_TEST(neg_zero == +0.01f && pos_zero == -0.01f, 
                    "swap(float): neg_zero = " + toString(neg_zero) + ", pos_zero = " + toString(pos_zero));

		std::cout << CYAN << "\n/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
		std::cout << CYAN << "/*                                    DOUBLE                                  */" << NC << std ::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;
		/* Test swap with double min and max */
        double double_min = std::numeric_limits<double>::min();
        double double_max = std::numeric_limits<double>::max();
        ::swap(double_min, double_max);
		ASSERT_TEST(double_min == std::numeric_limits<double>::max() && double_max == std::numeric_limits<double>::min(), 
					"swap(double): double_min = " + toString(double_min) + ", double_max = " + toString(double_max));

		/* Test min and max with double */
		ASSERT_TEST(::min(3.141592653589793, 2.718281828459045) == 2.718281828459045, 
					"min(double): min(3.141592653589793, 2.718281828459045) == 2.718281828459045");
		ASSERT_TEST(::max(3.141592653589793, 2.718281828459045) == 3.141592653589793, 
					"max(double): max(3.141592653589793, 2.718281828459045) == 3.141592653589793");

		/* Test swap with double min and max */
        double double_min_1 = std::numeric_limits<double>::min() - 1;
        double double_max_1 = std::numeric_limits<double>::max() + 1;
        ::swap(double_min_1, double_max_1);
        ASSERT_TEST(double_min_1 == std::numeric_limits<double>::max() + 1 && double_max_1 == std::numeric_limits<double>::min() - 1, 
                    "swap(double): double_min_1 = " + toString(double_min_1) + ", double_max_1 = " + toString(double_max_1));

		// Test min and max with -0.0 and +0.0
		ASSERT_TEST(::min(-0.01, +0.01) == -0.01, "min(double): min(-0.01, +0.01) == -0.01");
		ASSERT_TEST(::max(-0.01, +0.01) == +0.01, "max(double): max(-0.01, +0.01) == +0.01");

		return 0;
	}

	else
	{
		std::cout << RED << "Usage: ./whatever or ./whatever tester" << NC << std::endl;
		return 1;
	}
}

/* main.cpp */

