/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/02/25 19:49:51 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <string>
#include <iostream>

template <typename T>
void	addOne(T &x)
{
	x++;

	return ;
}

template <typename T>
void	testUpper(T &x)
{
	if (islower(x))
		x -= 32;

	return ;
}

void	printArray(int *array)
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << array[i];
	}
	std::cout << std::endl;
}

int main(void)
{
	std::string	test = "gyurtdgiuwwjdwwd766586913{}{}[]";
	char		*string = (char *)(test.c_str());
	int			size = test.size();

	int			testNum[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t		sizeNum		= 10;

	std::cout << "Before: [" << string << "]" << std::endl;
	iter(string, size, testUpper);
	std::cout << "After: [" << string << "]" << std::endl;

	std::cout << "Array before" << std::endl;
	printArray(testNum);
	iter(testNum, sizeNum, addOne);
	std::cout << "Array after" << std::endl;
	printArray(testNum);

	return (0);
}
