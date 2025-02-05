/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:04:12 by vpf               #+#    #+#             */
/*   Updated: 2025/02/05 19:25:48 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(Point const &p);
        Point(float const x, float const y);

        ~Point();

        Point &operator = (Point const &p);

        Fixed const   &getX(void) const;
        Fixed const   &getY(void) const;
};
