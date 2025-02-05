/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:04:07 by vpf               #+#    #+#             */
/*   Updated: 2025/02/06 00:37:03 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float   cross_2d(Point &a, Point &b)
{
    float   res;

    res = (a.getX().toFloat() * b.getY().toFloat()) - (a.getY().toFloat() * b.getX().toFloat());
    return (res);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    int     accum = 0;
    Point   ab(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
    Point   ac(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() - a.getY().toFloat());
    Point   bc(c.getX().toFloat() - b.getX().toFloat(), c.getY().toFloat() - b.getY().toFloat());

    
}