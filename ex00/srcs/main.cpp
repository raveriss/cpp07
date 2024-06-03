#include <iostream>
#include <string>
#include <sstream>


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
 * @brief Teste la conversion d'une chaîne de caractères et compare le résultat attendu
 */
void testConversion(const std::string& input, const std::string& expectedOutput)
{
    /* Création d'un objet ostringstream pour capturer la sortie */
    std::ostringstream buffer;

    /* Creation d'un pointeur rootCoutStream de type std::streambuf pour sauvegarder le tampon de flux courant de std::cout */
    std::streambuf *rootCoutStream;

    /* Sauvegarde du tampon de flux courant de std::cout */
    rootCoutStream = std::cout.rdbuf();

    /* Redirection de std::cout vers le tampon de flux buffer */
    std::cout.rdbuf(buffer.rdbuf());

    /* Print the expected and actual output */

    
    /* Restauration du tampon de flux d'origine de std::cout */
    std::cout.rdbuf(rootCoutStream);

    /* Capture the output in a string */
    std::string output = buffer.str();

    /* Print the expected and actual output */
    ASSERT_TEST(output == expectedOutput, "Input: " + input + "\n" + output);
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
