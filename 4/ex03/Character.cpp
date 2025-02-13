/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:41:08 by vpf               #+#    #+#             */
/*   Updated: 2025/02/13 02:34:31 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::~Character()
{
    std::cout
        << "Destructor Character"
    << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materiaInventory[i] != NULL)
            delete this->_materiaInventory[i];
    }

    return ;
}

Character::Character() : _name("DefaultC")
{
    std::cout
        << "Default Constructor Character"
    << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_materiaInventory[i] = NULL;
    }

    return ;
}

Character::Character(std::string const & name) : _name(name)
{
    std::cout
        << "Name Constructor Character"
    << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_materiaInventory[i] = NULL;
    }

    return ;
}

Character::Character(const Character &copy)
{
    std::cout
        << "Copy Constructor Character"
    << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_materiaInventory[i] = NULL;
    }
    *this = copy;

    return ;
}

Character &Character::operator = (const Character &other)
{
    if (this != &other)
    {
        this->_name = other._name;
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

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
    {
        std::cout << this->getName() << ": empty materia can't be equipped" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_materiaInventory[i] == NULL)
        {
            this->_materiaInventory[i] = m;
            std::cout << this->getName() << ": equips materia of type: " << m->getType() << " at index: " << i << std::endl;
            return ;
        }
    }

    std::cout << this->getName() << ": Inventory full, unequip a materia first" << std::endl;
    return ;
}

void Character::unequip(int idx)
{
    if (0 > idx || idx > 3)
        std::cout << this->getName() << ": Cannot unequip materia --> inventory index out of bounds" << std::endl;
    else if (this->_materiaInventory[idx] != NULL)
    {
        std::cout << this->getName() << ": unequips materia at index: " << idx << std::endl;
        this->_materiaInventory[idx] = NULL;
    }
    else
    {
        std::cout << this->getName() << ": Cannot unequip materia --> materia slot empty!" << std::endl;
    }

    return ;
}

void Character::use(int idx, ICharacter& target)
{
    if (0 > idx || idx > 3)
        std::cout << this->getName() << ": Cannot use materia --> Inventory index out of bounds" << std::endl;
    else if (this->_materiaInventory[idx] != NULL)
    {
        this->_materiaInventory[idx]->use(target);
    }
    else
    {
        std::cout << this->getName() << ": Cannot use materia --> materia slot empty!" << std::endl;
    }

    return ;
}

AMateria *	Character::getMateria( int idx ) {

	if (idx >= 0 && idx < 4)
		return (this->_materiaInventory[idx]);
	else
		return (NULL);
}

void	Character::printHUD( void ) {
	
	std::string	hudTitle = this->getName() + " HUD";

	std::cout << std::setw(COL_WIDTH * 4) << std::setfill('-') << "" << std::endl;
	std::cout << std::setw(COL_WIDTH * 4) << std::left << std::setfill(' ') << hudTitle << std::endl;
	std::cout << std::setw(COL_WIDTH * 4) << std::setfill('-') << "" << std::endl;
	
	std::cout << std::setw(COL_WIDTH) << std::right << std::setfill(' ') << "SLOT 0";
	std::cout << std::setw(COL_WIDTH) << std::right << std::setfill(' ') << "SLOT 1";
	std::cout << std::setw(COL_WIDTH) << std::right << std::setfill(' ') << "SLOT 2";
	std::cout << std::setw(COL_WIDTH) << std::right << std::setfill(' ') << "SLOT 3";
	std::cout << std::endl;
	std::cout << std::setw(COL_WIDTH * 4) << std::setfill('-') << "" << std::endl;

	for (int i = 0; i < 4; i++)
		std::cout << std::setw(COL_WIDTH) << std::right << std::setfill(' ') << (this->_materiaInventory[i]);
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << std::setw(COL_WIDTH) << std::right << std::setfill(' ') << (this->_materiaInventory[i] ? this->_materiaInventory[i]->getType() : "****");
	std::cout << std::endl;
	std::cout << std::setw(COL_WIDTH * 4) << std::setfill('-') << "" << std::endl;
}