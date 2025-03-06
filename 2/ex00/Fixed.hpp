/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:17:06 by vperez-f          #+#    #+#             */
/*   Updated: 2025/03/06 18:24:44 by vpf              ###   ########.fr       */
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
