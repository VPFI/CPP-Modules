/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/02/26 23:12:48 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try 
	{
		easyfind(vec, 3);
		easyfind(vec, 10);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::deque<int>	dq;

	dq.push_back(-323223);
	dq.push_back(0);
	dq.push_back(897);
	try
	{
		easyfind(dq, 897);
		easyfind(dq, -323224);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
