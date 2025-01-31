/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:06:18 by vperez-f          #+#    #+#             */
/*   Updated: 2025/01/31 20:39:18 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	int num_of_zombies = 40;
	Zombie	*horde;

	horde = zombieHorde(num_of_zombies, "Zombie");
	for (int i = 0; i < num_of_zombies; i++)
	{
		horde[i].announce();
	}
	delete[] horde;

	return (0);
}