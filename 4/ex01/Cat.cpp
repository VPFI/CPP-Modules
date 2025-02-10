/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:12:33 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 23:34:47 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _brain(new Brain)
{
    std::cout
        << "Default Cat constructor called"
    << std::endl;
    this->setType("Cat");

    return ;
}

Cat::Cat(const Cat &copy) : Animal(copy), _brain(new Brain)
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
    delete (this->_brain);

    return ;
}

Cat &Cat::operator = (const Cat &other)
{
    if (this != &other)
    {
        this->_type = other._type;
        *(this->_brain) = *(other._brain);
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

