/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/25 21:13:25 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template <typename T> class Array
{
	private:
		T			*_array;
		std::size_t	_size;

	public:
		Array();
		Array(std::size_t n);
		Array(const Array &copy);
		~Array();

		Array	&operator = (const Array &other);
		T		&operator [] (std::size_t pos) const;

		std::size_t	size(void) const;
};

#include "Array.tpp"
