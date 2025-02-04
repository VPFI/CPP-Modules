/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:16:59 by vperez-f          #+#    #+#             */
/*   Updated: 2025/02/04 20:17:24 by vperez-f         ###   ########.fr       */
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
	this->_bits = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n << this->_fractional_bits);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(n * (1 << this->_fractional_bits)));
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

std::ostream &operator << (std::ostream &out_s, const Fixed &f)
{
	return (out_s << f.toFloat());
}

int		Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_bits)	;
}
void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_bits = raw;		
}

int		Fixed::toInt( void ) const
{
	return (this->getRawBits() >> this->_fractional_bits);
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << this->_fractional_bits));
}
