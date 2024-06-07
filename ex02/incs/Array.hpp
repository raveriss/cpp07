/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:05:36 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/05 17:00:33 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclure les fichiers .hpp nécessaires */
#include <stdexcept>

/**
 * @brief Classe Array
*/
template <typename T>
class Array
{
    public:
        /* Constructeurs par défaut */
        Array();

        /* Constructeur avec un nombre d'éléments */
        Array(unsigned int n);

        /* Constructeur par copie */
        Array(const Array& other);

        /* Destructeur */
        ~Array();

        /* Surcharge de l'opérateur d'affectation */
        Array& operator=(const Array& other);

        /* Surcharge de l'opérateur [] */
        T& operator[](unsigned int index);

        /* Surcharge de l'opérateur [] const */
        const T& operator[](unsigned int index) const;

        /* Retourne la taille du tableau */
        unsigned int size() const;

    private:
        T* _elements;
        unsigned int _size;
};

/* Inclure les fichiers .tpp nécessaires */
#include "../srcs/Array.tpp"

/* Array.cpp */