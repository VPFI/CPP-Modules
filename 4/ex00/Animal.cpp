/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:12:40 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 18:41:50 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout
        << "Default Animal constructor called"
    << std::endl;

    return ;
}

Animal::Animal(const Animal &copy)
{
    std::cout
        << "Copy Animal constructor called"
    << std::endl;
    *this = copy;

    return ;
}

Animal::~Animal()
{
    std::cout
        << "Animal destructor called"
    << std::endl;    
}

Animal &Animal::operator = (const Animal &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

void    Animal::setType(std::string newType)
{
    this->_type = newType;

    return ;
}

std::string    Animal::getType() const
{
    return (this->_type);
}

void    Animal::makeSound() const
{
    std::cout
        << "Generic animal sound"
    << std::endl;

    return ;
}
