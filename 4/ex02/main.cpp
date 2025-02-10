/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:12:28 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 23:43:24 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void	testBasicAnimalArray(void)
{

	std::cout << "===========================================" << std::endl;
	std::cout << "Basic animal array test" << std::endl;
	std::cout << "===========================================" << std::endl;
	
	Animal *	spiri = new Cat();
	Animal * zoo[] =
	{
		new Cat(),
		new Dog(),
		new Dog(),
		new Cat()
	};
	
	for (int i = 0; i < 4; i++)
		zoo[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete zoo[i];
	delete spiri;
}

void	testAssignation(void)
{

	std::cout << "===========================================" << std::endl;
	std::cout << "Test assignment operator" << std::endl;
	std::cout << "===========================================" << std::endl;
	
	Dog		plat;
	Dog *	mars = new Dog(plat);

	std::cout << plat.getType() << std::endl;
	plat.makeSound();
	std::cout << mars->getType() << std::endl;
	mars->makeSound();
	delete mars;
}

void	testPointer(void)
{

	std::cout << "===========================================" << std::endl;
	std::cout << "Test pointer and self assignation" << std::endl;
	std::cout << "===========================================" << std::endl;

	Cat	og;
	Cat *	og2 = &og;
	const	Animal *cpy = new Cat(og);
	
	std::cout << og.getType() << std::endl;
	std::cout << cpy->getType() << std::endl;
	og = *og2;
	delete cpy;
}

int	main(void)
{
	//Animal	genericAnimal;
	
	testBasicAnimalArray();
	testAssignation();
	testPointer();
	return (0);
}