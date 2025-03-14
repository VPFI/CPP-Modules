/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:18:39 by vpf               #+#    #+#             */
/*   Updated: 2025/01/31 18:04:13 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	test(Zombie *main_zomb, Zombie randomChump)
{
	std::cout << "Out of main" << std::endl;
	Zombie	*second_zombie = newZombie("test");

	main_zomb->announce();
	second_zombie->announce();
	randomChump.announce();
	delete (second_zombie);
	std::cout << "Exiting test func scope" << std::endl;
}

int main(void)
{
	Zombie	*heap_zombie = newZombie("main");
	Zombie	chump;

	randomChump("Chumpito");
	test(heap_zombie, chump);
	delete (heap_zombie);
	std::cout << "Exiting main" << std::endl;
}
