/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:34 by vpf               #+#    #+#             */
/*   Updated: 2025/04/14 19:42:45 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe(std::vector<unsigned int> const &newInput) : _input(newInput)
{
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;

	return ;
}

PmergeMe &PmergeMe::operator = (PmergeMe const &other)
{
	if (this != &other)
	{
		this->_input = other.getInput();
	}

	return (*this);
}

PmergeMe::~PmergeMe()
{
	return ;
}

std::vector<unsigned int>	PmergeMe::getInput() const
{
	return (this->_input);
}

const char  *PmergeMe::WrongInput::what(void) const throw()
{
	return ("Error while sorting");
}

void    PmergeMe::sort()
{
	// pair
	// sort_pair
	// compare
	// swap
	// mult order
	static int	groupOrder = 1;
	int			size = this->_input.size();
	if (groupOrder > size)
		return ;

	int			pairs = size / groupOrder;

	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << "NUM[" << i << "]: " << this->_input.at(i) << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < pairs; i++)
	{
		
	}
	

}
