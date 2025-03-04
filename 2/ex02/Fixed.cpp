/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:16:59 by vperez-f          #+#    #+#             */
/*   Updated: 2025/03/04 19:52:48 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->_bits = 0;
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n << _fractional_bits);
}

Fixed::Fixed(const float n)
{
	//std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(n * (1 << _fractional_bits)));
}

Fixed::Fixed(const Fixed &f)
{	
	//std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

//--------------------------------OPERATORS--------------------------------//

Fixed	&Fixed::operator = (const Fixed &f)
{
	//std::cout << "Copy assignment overload called" << std::endl;
	if (this != &f)
	{
		this->setRawBits(f.getRawBits());
	}
	return (*this);
}

bool	Fixed::operator > (const Fixed &f)
{
	if (this->getRawBits() > f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator < (const Fixed &f)
{
	if (this->getRawBits() < f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator >= (const Fixed &f)
{
	if (this->getRawBits() >= f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator <= (const Fixed &f)
{
	if (this->getRawBits() <= f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator == (const Fixed &f)
{
	if (this->getRawBits() == f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator != (const Fixed &f)
{
	if (this->getRawBits() != f.getRawBits())
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator + (const Fixed &f)
{
	Fixed res(this->toFloat() + f.toFloat());

	return (res);
}

Fixed	Fixed::operator - (const Fixed &f)
{
	Fixed res(this->toFloat() - f.toFloat());

	return (res);
}

Fixed	Fixed::operator * (const Fixed &f)
{
	Fixed res(this->toFloat() * f.toFloat());

	return (res);
}

Fixed	Fixed::operator / (const Fixed &f)
{
	Fixed res(this->toFloat() / f.toFloat());

	return (res);
}

Fixed	&Fixed::operator ++ (void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	res(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (res);
}

Fixed	&Fixed::operator -- (void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	res(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (res);
}


std::ostream &operator << (std::ostream &out_s, const Fixed &f)
{
	return (out_s << f.toFloat());
}

//-------------------------------------------------------------------------//

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
	return (this->getRawBits() >> _fractional_bits);
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _fractional_bits));
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1.toFloat() < n2.toFloat())
		return (n1);
	else
		return (n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1.toFloat() > n2.toFloat())
		return (n1);
	else
		return (n2);
}
