/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:24:09 by vpf               #+#    #+#             */
/*   Updated: 2025/04/01 21:46:04 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout
        << "Default DiamondTrap constructor called"
    << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _name(name)
{
    std::cout
        << "Name DiamondTrap (" << name << ") constructor called"
    << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
	*this = copy;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor (" << _name << ") called" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator = (const DiamondTrap &c)
{
    std::cout << "DiamondTrap copy assignment called" << std::endl;
	if (this != &c)
	{
		this->_name = c._name;
		this->_attack_damage = c._attack_damage;
		this->_hit_points = c._hit_points;
		this->_energy_points = c._energy_points;
	}
	return (*this);
}

void    DiamondTrap::whoAmI()
{
    std::cout
        << "ClapTrap name: " << this->ClapTrap::_name
        << "\nDiamondTrap name: " << this->_name
    << std::endl;
}
