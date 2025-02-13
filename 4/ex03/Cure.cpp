/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:39:28 by vpf               #+#    #+#             */
/*   Updated: 2025/02/13 02:49:20 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::~Cure()
{
    std::cout
        << "Destructor Cure"
    << std::endl;
    return ;
}

Cure::Cure() : AMateria("cure")
{
    std::cout
        << "Default Constructor Cure"
    << std::endl;

    return ;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
    std::cout
        << "Copy Constructor Cure"
    << std::endl;
    *this = copy;

    return ;
}

Cure &Cure::operator = (const Cure &other)
{
    if (this != &other)
    {
        this->_type = other._type; // Doesn't make sense as of now || It would if it had more attr?
    }
    return (*this);
}

AMateria* Cure::clone() const
{
    AMateria *res = new Cure;

    return (res);
}

void Cure::use(ICharacter& target)
{
    std::cout
        << "* heals " << target.getName() << "'s wounds *"
    << std::endl;

    return ;
}
