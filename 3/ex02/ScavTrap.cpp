/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:01:39 by vpf               #+#    #+#             */
/*   Updated: 2025/02/08 00:16:29 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout
        << "Default ScavTrap constructor called"
    << std::endl;
    this->set_hit_points(100);
    this->set_energy_points(50);
    this->set_attack_damage(20);
}

ScavTrap::ScavTrap(std::string name) 
{
    std::cout
        << "Name ScavTrap (" << name << ") constructor called"
    << std::endl;
    this->set_name(name);
    this->set_hit_points(100);
    this->set_energy_points(50);
    this->set_attack_damage(20);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor (" << _name << ") called" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator = (const ScavTrap &c)
{
    std::cout << "ScavTrap copy assignment called" << std::endl;
	if (this != &c)
	{
		this->_name = c._name;
		this->_attack_damage = c._attack_damage;
		this->_hit_points = c._hit_points;
		this->_energy_points = c._energy_points;
	}
	return (*this);
}

void	ScavTrap::guardGate(void)
{
    std::cout
        << "ScavTrap (" << this->_name
        << ") is now in gate keeper mode"
    << std::endl;    
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hit_points <= 0)
    {
        std::cout
            << "(" << this->_name << ") is dead."
            << " Cannot attack!"
        << std::endl;
        return ;
    }
	if (this->_energy_points < 1)
	{
		std::cout
			<< "Scavtrap (" << this->_name
			<< ") out of energy!"
		<< std::endl;
		return ;
	}
	this->_energy_points -= 1;
	std::cout
		<< "Scavtrap (" << this->_name
		<< ") attacks " << target
		<< " causing " << this->_attack_damage << " points of damage!"
	<< std::endl;
}
