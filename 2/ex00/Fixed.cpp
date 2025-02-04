/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:16:59 by vperez-f          #+#    #+#             */
/*   Updated: 2025/02/04 16:13:02 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
}

Fixed::Fixed(const Fixed &f)
{	
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed	&Fixed::operator = (const Fixed &f)
{
	std::cout << "Copy assignment overload called" << std::endl;
	if (this != &f)
	{
		this->setRawBits(f.getRawBits());
	}
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point)	;
}
void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point = raw;		
}
