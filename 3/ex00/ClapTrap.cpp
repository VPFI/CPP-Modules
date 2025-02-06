/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:28 by vperez-f          #+#    #+#             */
/*   Updated: 2025/02/06 18:33:32 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(10) {std::cout << "Default constructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator = (const ClapTrap &c)
{
	if (this != &c)
	{
		this->_name = c.get_name();
		this->_attack_damage = c.get_attack_damage();
		this->_hit_points = c.get_hit_points();
		this->_energy_points = c.get_energy_points();
	}
	return (*this);
}

std::string	ClapTrap::get_name() const
{
	return (this->_name);
}

int			ClapTrap::get_hit_points() const
{
	return (this->_hit_points);
}

int			ClapTrap::get_energy_points() const
{
	return (this->_energy_points);
}

int			ClapTrap::get_attack_damage() const
{
	return (this->_attack_damage);
}


void		ClapTrap::set_name(std::string new_name)
{
	this->_name = new_name;
}

void		ClapTrap::set_hit_points(int amount)
{
	this->_hit_points = amount;
}

void		ClapTrap::set_energy_points(int amount)
{
	this->_energy_points = amount;
}

void		ClapTrap::set_attack_damage(int amount)
{
	this->_attack_damage = amount;
}

//---------------------------------------------------------------//

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points < 1)
	{
		std::cout
			<< "ClapTrap " << this->_name
			<< " out of energy!"
		<< std::endl;
		return ;
	}
	this->_energy_points -= 1;
	std::cout
		<< "ClapTrap " << this->_name
		<< " attacks " << target
		<< " causing " << this->_attack_damage << " points of damage!"
	<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points -= amount;
	if (this->_hit_points < 0)
		this->set_hit_points(0);
	std::cout
		<< "ClapTrap " << this->_name
		<< " takes " << amount << " points of damage!"
	<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points < 1)
	{
		std::cout
			<< "ClapTrap " << this->_name
			<< " out of energy!"
		<< std::endl;
		return ;
	}
	this->_energy_points -= 1;
	this->_hit_points += amount;
	std::cout
		<< "ClapTrap " << this->_name
		<< " recovers " << amount << " hit points!"
	<< std::endl;
}
