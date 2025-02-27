/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/02/27 01:56:28 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <list>

#define MAX_SIZE 500000

int main(void)
{
	std::list<int>	list;

	for (unsigned int i = 0; i < MAX_SIZE; i++)
		list.push_back(i);

	Span	s(MAX_SIZE);
	s.addNumber(list.begin(), list.end());
	std::cout << "Shortest span = " << s.shortestSpan() << std::endl;
	std::cout << "Longest span = " << s.longestSpan() << std::endl;

	std::cout << std::endl;
	
	Span	s2(5);
	
	try
	{
		s2.addNumber(25665);
		s2.addNumber(-2000);
		s2.addNumber(897329732);
		s2.addNumber(0);
		s2.addNumber(-3);
		s2.addNumber(41);
		s2.addNumber(7);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Shortest span = " << s2.shortestSpan() << std::endl;
		std::cout << "Longest span = " << s2.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Span	s3(MAX_SIZE);
	std::srand(std::time(NULL));
	
	try
	{
		for (int i = 0; i < MAX_SIZE; i++)
			s3.addNumber((int)(std::rand() / (float)RAND_MAX * 1000000));
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Shortest span = " << s3.shortestSpan() << std::endl;
		std::cout << "Longest span = " << s3.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
