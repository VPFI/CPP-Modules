/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:17:06 by vperez-f          #+#    #+#             */
/*   Updated: 2025/02/04 16:03:49 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int					_fixed_point;
		static const int	_fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed &operator = (const Fixed &f);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};
