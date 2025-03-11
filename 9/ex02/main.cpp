/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/03/07 18:40:44 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return (1);
	}
	
	try
	{
		std::vector<unsigned int> nums;
		for (int i = 1; i < argc; i++)
			nums.emplace_back(std::atof(argv[i]));
		PmergeMe	calc(nums);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    return (0);
}
