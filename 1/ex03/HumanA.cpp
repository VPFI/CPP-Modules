/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:21:47 by vpf               #+#    #+#             */
/*   Updated: 2025/02/01 17:52:15 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &newWeapon): _weapon(newWeapon)
{
    this->_name = name;
    return ;
}
HumanA::~HumanA(void)
{
    return ;
}

void    HumanA::attack(void)
{
    std::cout << this->_name << ": attacks with their " << this->_weapon.getType() << std::endl;
}
