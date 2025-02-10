/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:55:44 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 18:55:46 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout
        << "Default WrongAnimal constructor called"
    << std::endl;

    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout
        << "Copy WrongAnimal constructor called"
    << std::endl;
    *this = copy;

    return ;
}

WrongAnimal::~WrongAnimal()
{
    std::cout
        << "WrongAnimal destructor called"
    << std::endl;    
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

void    WrongAnimal::setType(std::string newType)
{
    this->_type = newType;

    return ;
}

std::string    WrongAnimal::getType() const
{
    return (this->_type);
}

void    WrongAnimal::makeSound() const
{
    std::cout
        << "Generic WrongAnimal sound"
    << std::endl;

    return ;
}
