/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/04/14 19:42:26 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return (1);
	}
	
	try
	{
		std::vector<unsigned int> nums;
		for (int i = 1; i < argc; i++)
			nums.push_back(std::atof(argv[i]));
		PmergeMe	calc(nums);
		calc.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    return (0);
}
