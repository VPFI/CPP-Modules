/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:14:30 by vpf               #+#    #+#             */
/*   Updated: 2025/02/27 01:47:08 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <stdint.h>


class Span
{
    private:
        std::size_t     _current;
        std::size_t     _capacity;
        int             *_data;

    public:
        Span();
        Span(std::size_t n);
        Span(Span const &copy);
        ~Span();

        Span    &operator = (Span const &other);

        void    addNumber(int newNumber);
        
        template<typename ITERATOR>
        void	addNumber(ITERATOR firstInRange, ITERATOR lastInRange);
        
        size_t  shortestSpan(void) const;
        size_t  longestSpan(void) const;
};

template<typename ITERATOR>
void	Span::addNumber(ITERATOR firstInRange, ITERATOR lastInRange)
{
	for (; firstInRange != lastInRange; firstInRange++)
		this->addNumber(*firstInRange);
}
