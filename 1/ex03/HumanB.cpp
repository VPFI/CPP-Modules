/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:29:43 by vpf               #+#    #+#             */
/*   Updated: 2025/02/01 17:54:53 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
    this->_name = name;
    return ;
}
HumanB::~HumanB()
{
    return ;
}

void    HumanB::attack( void )
{
    std::cout << this->_name << ": attacks with their " << this->_weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &newWeapon)
{
    this->_weapon  = &newWeapon;
    return ;
}
