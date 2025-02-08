/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:40:51 by vpf               #+#    #+#             */
/*   Updated: 2025/02/08 00:15:12 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout
        << "Default FragTrap constructor called"
    << std::endl;
    this->set_hit_points(100);
    this->set_energy_points(100);
    this->set_attack_damage(30);
}

FragTrap::FragTrap(std::string name) 
{
    std::cout
        << "Name FragTrap (" << name << ") constructor called"
    << std::endl;
    this->set_name(name);
    this->set_hit_points(100);
    this->set_energy_points(100);
    this->set_attack_damage(30);
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "Copy FragTrap constructor called" << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor (" << _name << ") called" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator = (const FragTrap &c)
{
    std::cout << "FragTrap copy assignment called" << std::endl;
	if (this != &c)
	{
		this->_name = c._name;
		this->_attack_damage = c._attack_damage;
		this->_hit_points = c._hit_points;
		this->_energy_points = c._energy_points;
	}
	return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    if (this->_hit_points <= 0)
    {
        std::cout
            << "(" << this->_name << ") is dead."
            << " Cannot request high fives :("
        << std::endl;
        return ;
    }

   std::cout
        << "(" << this->_name << ") is requesting a high five!."
        << " (Please input 5 or enter to make him happy)"
    << std::endl;

    std::string input;
    while (getline(std::cin, input) && !(std::cin.eof()))
    {
        if (!input.empty() && input != "5")
        {
            std::cout
                << "That's not a high five!"
            << std::endl;
            continue ;
        }
        std::cout
                << "YAY!"
        << std::endl;
        break ;
    }
}
