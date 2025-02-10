/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:12:33 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 18:43:28 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout
        << "Default Cat constructor called"
    << std::endl;
    this->setType("Cat");

    return ;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout
        << "Copy Cat constructor called"
    << std::endl;
    *this = copy;

    return ;
}

Cat::~Cat()
{
    std::cout
        << "Cat destructor called"
    << std::endl;

    return ;
}

Cat &Cat::operator = (const Cat &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout
        << "MIAUUUUUU"
    << std::endl;

    return ;
}
