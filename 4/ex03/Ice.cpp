/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:39:12 by vpf               #+#    #+#             */
/*   Updated: 2025/02/13 02:48:15 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::~Ice()
{
    std::cout
        << "Destructor Ice"
    << std::endl;
    return ;
}

Ice::Ice() : AMateria("ice")
{
    std::cout
        << "Default Constructor Ice"
    << std::endl;

    return ;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
    std::cout
        << "Copy Constructor Ice"
    << std::endl;
    *this = copy;

    return ;
}

Ice &Ice::operator = (const Ice &other)
{
    if (this != &other)
    {
        this->_type = other._type; // Doesn't make sense as of now || It would if it had more attr?
    }
    return (*this);
}

AMateria* Ice::clone() const
{
    AMateria *res = new Ice();

    return (res);
}

void Ice::use(ICharacter& target)
{
    std::cout
        << "* shoots an ice bolt at " << target.getName() << " *"
    << std::endl;

    return ;
}