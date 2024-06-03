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
    }
    
    /**
     * Tester
     */
    if (argc == 2 && strcmp(argv[1], "tester") == 0)
    {
        // Test swap with integers
        int x = 1, y = 2;
        ::swap(x, y);
        ASSERT_TEST(x == 2 && y == 1, "swap(int): x = " + toString(x) + ", y = " + toString(y));

        // Test swap with strings
        std::string str1 = "hello", str2 = "world";
        ::swap(str1, str2);
        ASSERT_TEST(str1 == "world" && str2 == "hello", "swap(string): str1 = " + str1 + ", str2 = " + str2);

        // Test min with integers
        ASSERT_TEST(::min(3, 4) == 3, "min(int): min(3, 4) == 3");
        ASSERT_TEST(::min(5, 2) == 2, "min(int): min(5, 2) == 2");

        // Test min with strings
        ASSERT_TEST(::min(std::string("apple"), std::string("banana")) == "apple", "min(string): min('apple', 'banana') == 'apple'");

        // Test max with integers
        ASSERT_TEST(::max(3, 4) == 4, "max(int): max(3, 4) == 4");
        ASSERT_TEST(::max(5, 2) == 5, "max(int): max(5, 2) == 5");

        // Test max with strings
        ASSERT_TEST(::max(std::string("apple"), std::string("banana")) == "banana", "max(string): max('apple', 'banana') == 'banana'");

        // Test min and max with INT_MIN and INT_MAX
        ASSERT_TEST(::min(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) == std::numeric_limits<int>::min(), 
                    "min(int): min(INT_MIN, INT_MAX) == INT_MIN");
        ASSERT_TEST(::max(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) == std::numeric_limits<int>::max(), 
                    "max(int): max(INT_MIN, INT_MAX) == INT_MAX");

        // Test min and max with just below INT_MIN and just above INT_MAX using long long to avoid overflow
        long long int min_below = static_cast<long long int>(std::numeric_limits<int>::min()) - 1;
        long long int max_above = static_cast<long long int>(std::numeric_limits<int>::max()) + 1;
        ASSERT_TEST(::min(min_below, max_above) == min_below, 
                    "min(long long): min(INT_MIN-1, INT_MAX+1) == INT_MIN-1");
        ASSERT_TEST(::max(min_below, max_above) == max_above, 
                    "max(long long): max(INT_MIN-1, INT_MAX+1) == INT_MAX+1");

        // Test min and max with float
        ASSERT_TEST(::min(3.14f, 2.71f) == 2.71f, "min(float): min(3.14f, 2.71f) == 2.71f");
        ASSERT_TEST(::max(3.14f, 2.71f) == 3.14f, "max(float): max(3.14f, 2.71f) == 3.14f");

        // Test min and max with double
        ASSERT_TEST(::min(3.141592653589793, 2.718281828459045) == 2.718281828459045, 
                    "min(double): min(3.141592653589793, 2.718281828459045) == 2.718281828459045");
        ASSERT_TEST(::max(3.141592653589793, 2.718281828459045) == 3.141592653589793, 
                    "max(double): max(3.141592653589793, 2.718281828459045) == 3.141592653589793");

        // Test min and max with -0.0 and +0.0
        ASSERT_TEST(::min(-0.0, +0.0) == -0.0, "min(double): min(-0.0, +0.0) == -0.0");
        ASSERT_TEST(::max(-0.0, +0.0) == +0.0, "max(double): max(-0.0, +0.0) == +0.0");

        return 0;
    }

    if (argc == 2 && strcmp(argv[1], "tester") != 0)
    {
        std::cout << RED << "Usage: ./whatever or ./whatever [tester]" << NC << std::endl;
        return 1;
    }

    if (argc > 2)
    {
        std::cout << RED << "Usage: ./whatever or ./whatever [tester]" << NC << std::endl;
        return 1;
    }
    return 0;
}

/* main.cpp */
