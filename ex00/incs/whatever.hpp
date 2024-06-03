/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:33:36 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/04 00:33:37 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T &min(const T &a, const T &b)
{
    return (a < b ? a : b);
}

template <typename T>
const T &max(const T &a, const T &b)
{
    return (a > b ? a : b);
}

/* whatever.hpp */