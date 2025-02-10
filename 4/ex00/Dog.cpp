/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:12:37 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 18:43:03 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout
        << "Default Dog constructor called"
    << std::endl;
    this->setType("Dog");

    return ;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout
        << "Copy Dog constructor called"
    << std::endl;
    *this = copy;
}

Dog::~Dog()
{
    std::cout
        << "Dog destructor called"
    << std::endl;    
}

Dog &Dog::operator = (const Dog &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout
        << "GUAUUUUUU"
    << std::endl;

    return ;
}