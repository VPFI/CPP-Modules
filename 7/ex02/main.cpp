/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/04/13 14:50:34 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	Array<int>	test;
	Array<int>	test2(6);

	test2[0] = 1;
	Array<int>	test3(test2);
	test = test2;

	std::cout << test[0] << std::endl;
	std::cout << test2[0] << std::endl;
	std::cout << test3[0] << std::endl;
	std::cout << test4[0] << std::endl;


	// std::srand(std::time(NULL));
	// const std::size_t	size = std::rand() % 100;

	// const Array<int>	numbers(size);
	// for (std::size_t i = 0; i < numbers.size(); i++)
	// 	numbers[i] = std::rand();

	// std::cout << "ARRAY OF SIZE " << size << "[0, " << (size - 1) << "]" << std::endl;
	// std::cout << "-----------------------------" << std::endl;
	// for (std::size_t i = 0; i < 10; i++)
	// {
	// 	std::size_t index = std::rand() % 100;
	// 	try
	// 	{
	// 		int tmp = numbers[index];
	// 		std::cout << "number[" << index << "] = " << tmp << std::endl;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << "number[" << index << "] = " << e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl << std::endl;
	
	// Array<std::string>	words(5);

	// words[0] = "Animal";
	// words[1] = "Zoo";
	// words[2] = "Zebra";
	// words[3] = "Snake";
	// words[4] = "Lion";

	// Array<std::string>	words2 = words;

	// words2[0] = "Car";
	// words2[1] = "Speed";
	// words2[2] = "Wheel";
	// words2[3] = "Driver";
	// words2[4] = "Chasis";

	// for (int i = -1; i < static_cast<int>(words.size() + 3); i++)
	// {
	// 	try
	// 	{
	// 		std::string cache1 = words[i];
	// 		std::string cache2 = words2[i];
	// 		std::cout << "word[" << i << "] = " << cache1 << " - > ";
	// 		std::cout << "word2[" << i << "] = " << cache2 << std::endl;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << "word[" << i << "] = " << e.what() << " - > ";
	// 		std::cout << "word2[" << i << "] = " << e.what() << std::endl;
	// 	}
	// }

	// Array<std::string>	nullTest;
	// try
	// {
	// 	std::cout << "word = " << nullTest[0] << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << "word = " << e.what() << std::endl;
	// }
}
