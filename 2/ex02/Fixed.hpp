/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:17:06 by vperez-f          #+#    #+#             */
/*   Updated: 2025/02/04 20:58:35 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int					_bits;
		static const int	_fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &f);

		~Fixed();


		Fixed &operator = (const Fixed &f);

		bool operator > (const Fixed &f);
		bool operator < (const Fixed &f);
		bool operator >= (const Fixed &f);
		bool operator <= (const Fixed &f);
		bool operator == (const Fixed &f);
		bool operator != (const Fixed &f);

		Fixed operator + (const Fixed &f);
		Fixed operator - (const Fixed &f);
		Fixed operator * (const Fixed &f);
		Fixed operator / (const Fixed &f);

		Fixed &operator ++ (void);
		Fixed operator ++ (int);
		Fixed &operator -- (void);
		Fixed operator -- (int);

		friend std::ostream &operator << (std::ostream &out_s, const Fixed &f);

		static Fixed &min(Fixed &n1, Fixed &n2);
		static const Fixed &min(const Fixed &n1, const Fixed &n2);
		static Fixed &max(Fixed &n1, Fixed &n2);
		static const Fixed &max(const Fixed &n1, const Fixed &n2);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;
};
