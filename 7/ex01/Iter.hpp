/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/24 18:53:12 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

template <typename T>

void iter(T *array, std::size_t size, void (*f)(T &))
{
	if (array == NULL)
		return ;

	for (std::size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}

	return ;
}
