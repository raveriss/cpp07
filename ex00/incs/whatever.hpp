/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:33:36 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/04 17:22:34 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/**
 * @brief Swaps two values
 */
template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Returns the minimum value between two values
 */
template <typename T>
const T &min(const T &a, const T &b)
{
    return (a < b ? a : b);
}

/**
 * @brief Returns the maximum value between two values
 */
template <typename T>
const T &max(const T &a, const T &b)
{
    return (a > b ? a : b);
}

/* whatever.hpp */