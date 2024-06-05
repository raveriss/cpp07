/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:03:09 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/05 10:05:29 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclure les fichiers .hpp nécessaires */
#include "../incs/Array.hpp"

/**
 * @brief Constructeur par défaut
*/
template <typename T>
Array<T>::Array()
: _elements(NULL), _size(0)
{}

/**
 * @brief Constructeur avec un nombre d'éléments
*/
template <typename T>
Array<T>::Array(unsigned int n)
: _elements(new T[n]()), _size(n)
{}

/**
 * @brief Constructeur par copie
*/
template <typename T>
Array<T>::Array(const Array& other)
: _elements(new T[other._size]), _size(other._size)
{
    for (unsigned int i = 0; i < _size; ++i)
    {
        _elements[i] = other._elements[i];
    }
}

/**
 * @brief Destructeur
*/
template <typename T>
Array<T>::~Array()
{
    delete[] _elements;
}

/**
 * @brief Surcharge de l'opérateur d'affectation
*/
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _elements;

        _size = other._size;
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
        {
            _elements[i] = other._elements[i];
        }
    }
    return *this;
}

/**
 * @brief Surcharge de l'opérateur []
*/
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _elements[index];
}

/**
 * @brief Surcharge de l'opérateur [] const
*/
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _elements[index];
}

/**
 * @brief Retourne la taille du tableau
*/
template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

/* Array.cpp */