/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/24 18:01:28 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> T max(T x, T y)
{
	return (x > y) ? x : y;
}

template <typename T> T min(T x, T y)
{
	return (x < y) ? x : y;
}

template <typename T> void swap(T &x, T &y)
{
	T	temp = x;

	x = y;
	y = temp;

	return ;
}
