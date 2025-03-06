/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:04:09 by vpf               #+#    #+#             */
/*   Updated: 2025/03/05 20:00:31 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::~Point() { }

Point::Point() : _x(0), _y(0) { }

Point::Point(Point const &p) : _x(p.getX()), _y(p.getY()) { }

Point::Point(float const x, float const y) : _x(x), _y(y) { }

Point &Point::operator = (Point const &p)
{
    (void)p;

    return (*this);
}

Fixed const   &Point::getX(void) const
{
    return (this->_x);
}

Fixed const   &Point::getY(void) const
{
    return (this->_y);
}
