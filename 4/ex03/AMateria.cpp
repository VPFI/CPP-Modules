/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:15:54 by vpf               #+#    #+#             */
/*   Updated: 2025/02/13 02:06:28 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::~AMateria()
{
    std::cout
        << "Destructor AMateria"
    << std::endl;

    return ;
}

AMateria::AMateria() : _type("Undetermined")
{
    std::cout
        << "Default Constructor AMateria"
    << std::endl;

    return ;
}

AMateria::AMateria(const AMateria &copy)
{
    std::cout
        << "Copy Constructor AMateria"
    << std::endl;
    *this = copy;

    return ;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout
        << "Type Constructor AMateria"
    << std::endl;

    return ;
}

AMateria &AMateria::operator = (const AMateria &other)
{
    if (this != &other)
    {
        this->_type = other._type; // ???? clone dream is dead
    }
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout
        << "* Undetermined materia action aimed at " << target.getName() << " *"
    << std::endl;

    return ;
}
