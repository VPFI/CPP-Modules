/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:14:04 by vpf               #+#    #+#             */
/*   Updated: 2025/04/16 18:12:23 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _current(0), _capacity(0), _data(NULL)
{
    return ;
}

Span::Span(std::size_t n) : _current(0), _capacity(n), _data(new int[n])
{
    return ;
}

Span::Span(Span const &copy) : _data(NULL)
{
    *this = copy;

    return ;
}

Span::~Span()
{
    if (this->_data)
        delete[] this->_data;

    return ;
}

Span    &Span::operator = (Span const &other)
{
    if (this != &other)
    {
        if (this->_data)
            delete[] this->_data;
        this->_capacity = other._capacity;
        this->_current = other._current;
        this->_data = new int[this->_capacity];
        for (std::size_t i = 0; i < this->_capacity; i++)
        {
            this->_data[i] = other._data[i];
        }
    }

    return (*this);
}

void    Span::addNumber(int newNumber)
{
    if (this->_current >= this->_capacity)
        throw (std::runtime_error("Span at maximmum capacity"));
    this->_data[_current] = newNumber;
    _current++;

    return ;
}

static bool is_sorted(int *begin, int *end)
{
    for (int *it = begin; it < end - 1; it++)
    {
        if (*it > *(it + 1))
        {
            return (false);
        }
    }
    return (true);
}

size_t    Span::shortestSpan() const
{
    if (this->_current < 2)
        throw (std::runtime_error("Not enough numbers to calculate Span"));
    size_t  diff = 0;
    size_t  res = SIZE_MAX;

    Span    temp(*this);

    if (!(is_sorted(temp._data, temp._data + this->_current)))
        std::sort(temp._data, temp._data + this->_current);

    for (std::size_t i = 0; i < (temp._current - 1); i++)
    {
        diff = std::abs(this->_data[i + 1] - this->_data[i]);
        if (diff < res)
            res = diff;
    }

    return (res);
}

size_t    Span::longestSpan() const
{
    if (this->_current < 2)
        throw (std::runtime_error("Not enough numbers to calculate Span"));

    int max = this->_data[0]; // you can use min-max but this is more efficient
    int min = this->_data[0]; // you can use min-max but this is more efficient

    for (std::size_t i = 1; i < this->_current; i++)
    {
        if (this->_data[i] > max)
            max = this->_data[i];
        if (this->_data[i] < min)
            min = this->_data[i];
    }

    return (std::abs(max - min));
}
