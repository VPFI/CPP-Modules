/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/02/24 17:45:34 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cmath>
#include <ctime>
#include <iostream>

float	unitRand()
{
	srand(std::time(NULL));

	return (rand() / (float)RAND_MAX);
}

Base	*generate(void)
{
	Base	*res;
	float	p = unitRand();

	if (p < 0.333)
	{
		res = new A;
	}
	else if (p < 0.666)
	{
		res = new B;
	}
	else
	{
		res = new C;
	}
	return (res);
}

void	identify(Base *p)
{
	A	*TypeA;
	B	*TypeB;
	C	*TypeC;

	TypeA = dynamic_cast<A*>(p);
	TypeB = dynamic_cast<B*>(p);
	TypeC = dynamic_cast<C*>(p);

	if (TypeA)
		std::cout << "Base is of Type A" << std::endl;
	else if (TypeB)
		std::cout << "Base is of Type B" << std::endl;
	else if (TypeC)
		std::cout << "Base is of Type C" << std::endl;
	else
		std::cout << "Base is of unknown Type" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&TypeA = dynamic_cast<A&>(p);
		std::cout << "Base is of Type A" << std::endl;
		(void)TypeA;
		return ;
	}
	catch(std::exception& e) {}

	try
	{
		B	&TypeB = dynamic_cast<B&>(p);
		std::cout << "Base is of Type B" << std::endl;
		(void)TypeB;
		return ;
	}
	catch(std::exception& e) {}

	try
	{
		C	&TypeC = dynamic_cast<C&>(p);
		std::cout << "Base is of Type C" << std::endl;
		(void)TypeC;
		return ;
	}
	catch(std::exception& e) {}

	std::cout << "Base is of unknown Type" << std::endl;
	return ;

}

int	main()
{
	Base *	ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete (ptr);
	return (0);
}
