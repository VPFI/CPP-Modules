/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:34:04 by vperez-f          #+#    #+#             */
/*   Updated: 2025/04/13 14:50:25 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	return ;	
}

template <typename T>
Array<T>::Array(std::size_t n) : _array(new T[n]()), _size(n)
{
	return ;
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	*this = copy;
	return ;
}

template <typename T>
Array<T>::~Array()
{
	if (this->_array)
		delete[] (this->_array);
	return ;
}

template <typename T>
Array<T>	&Array<T>::operator = (const Array &other)
{
	if (this != &other)
	{
		delete[] (this->_array);
		this->_size = other._size;
		if (this->_size != 0)
			this->_array = new T[this->_size];
		else
			this->_array = NULL;
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator [] (std::size_t pos) const
{
	if (this->_array == NULL)
		throw (std::runtime_error("Error: Array is empty"));
	if (pos >= this->_size)
		throw (std::out_of_range("Error: Array out of bounds"));
	return (this->_array[pos]);
}

template <typename T>
std::size_t	Array<T>::size(void) const
{
	return (this->_size);
}
