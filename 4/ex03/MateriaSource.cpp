/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:49:20 by vpf               #+#    #+#             */
/*   Updated: 2025/02/13 02:50:49 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::~MateriaSource()
{
    std::cout
        << "Destructor MateriaSource"
    << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materiaInventory[i])
            delete this->_materiaInventory[i];
    }

    return ;
}

MateriaSource::MateriaSource()
{
    std::cout
        << "Default Constructor MateriaSource"
    << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_materiaInventory[i] = NULL;
    }

    return ;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    std::cout
        << "Copy Constructor MateriaSource"
    << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_materiaInventory[i] = NULL;
    }
    *this = copy;

    return ;
}

MateriaSource &MateriaSource::operator = (const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_materiaInventory[i] != NULL)
            {
                delete this->_materiaInventory[i];
                this->_materiaInventory[i] = NULL;
            }
            else if (other._materiaInventory[i])
                this->_materiaInventory[i] = other._materiaInventory[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materiaInventory[i] == NULL)
        {
            this->_materiaInventory[i] = m;
            return ;
        }
    }

    std::cout << "Source: Materia list at maximum capacity" << std::endl;
    return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materiaInventory[i])
        {
            if (type == this->_materiaInventory[i]->getType())
                return (this->_materiaInventory[i]->clone());
        }
    }
    std::cout << "Unknown materia type" << std::endl;

    return (NULL);
}