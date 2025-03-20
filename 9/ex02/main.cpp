/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/03/12 21:07:49 by vperez-f         ###   ########.fr       */
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
		nums.push_back(1);
		nums.push_back(2);
		nums.push_back(3);
		nums.push_back(4);
		PmergeMe	calc(nums);
		calc.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    return (0);
}
