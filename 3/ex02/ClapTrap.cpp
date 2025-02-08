/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:28 by vperez-f          #+#    #+#             */
/*   Updated: 2025/02/08 00:50:27 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : 
		 _hit_points(10), _energy_points(10), _attack_damage(0) 
		{std::cout << "Default ClapTrap constructor called" << std::endl;}

ClapTrap::ClapTrap(std::string name) : 
		_name(name), _hit_points(10), 
		_energy_points(10), _attack_damage(0) 
		{std::cout << "Name ClapTrap (" << name << ") constructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor (" << _name << ") called" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator = (const ClapTrap &c)
{
	std::cout << "ClapTrap copy assignment called" << std::endl;
	if (this != &c)
	{
		this->_name = c._name;
		this->_attack_damage = c._attack_damage;
		this->_hit_points = c._hit_points;
		this->_energy_points = c._energy_points;
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
			<< "ClapTrap (" << this->_name
			<< ") out of energy!"
		<< std::endl;
		return ;
	}
	this->_energy_points -= 1;
	std::cout
		<< "ClapTrap (" << this->_name
		<< ") attacks " << target
		<< " causing " << this->_attack_damage << " points of damage!"
	<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
    {
        std::cout
            << "(" << this->_name << ") is already dead."
        << std::endl;
        return ;
    }
	this->_hit_points -= amount;
	std::cout
		<< "ClapTrap (" << this->_name
		<< ") takes " << amount << " points of damage! "
		<< (this->_hit_points < 0 ? 0 : this->_hit_points) << " HP remaining!";
	if (this->_hit_points < 0)
	{
		this->set_hit_points(0);
		std::cout
			<< " ClapTrap (" << this->_name
			<< ") dies!";
	}
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
    {
        std::cout
            << "(" << this->_name << ") is dead."
            << " Cannot repair itself"
        << std::endl;
        return ;
    }
	if (this->_energy_points < 1)
	{
		std::cout
			<< "ClapTrap (" << this->_name
			<< ") out of energy!"
		<< std::endl;
		return ;
	}
	this->_energy_points -= 1;
	this->_hit_points += amount;
	std::cout
		<< "ClapTrap (" << this->_name
		<< ") recovers " << amount << " hit points!"
	<< std::endl;
}
