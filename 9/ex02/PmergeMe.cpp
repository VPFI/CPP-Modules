/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:34 by vpf               #+#    #+#             */
/*   Updated: 2025/03/10 19:14:34 by vpf              ###   ########.fr       */
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
    return ("Error while computing");
}

void    PmergeMe::sort()
{
    
}
