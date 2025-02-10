/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:12:10 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 23:32:28 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout
        << "Default Brain constructor called"
    << std::endl;

    return ;
}

Brain::Brain(const Brain &copy)
{
    std::cout
        << "Copy Brain constructor called"
    << std::endl;
    *this = copy;

    return ;
}

Brain::~Brain()
{
    std::cout
        << "Brain destructor called"
    << std::endl;

    return ;
}

Brain &Brain::operator = (const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return (*this);
}
