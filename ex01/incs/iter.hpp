/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:38:13 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/07 15:28:05 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/**
 * @brief Iterates over an array of elements
*/
template <typename T>
void iter(T *array, int length, void (*func)(T &))
{
    for (int i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

/* iter.hpp */
