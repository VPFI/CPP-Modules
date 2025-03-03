/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:08:08 by vpf               #+#    #+#             */
/*   Updated: 2025/03/03 14:08:06 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon()
{
    return ;
}

Weapon::Weapon(std::string type)
{
    setType(type);
    return ;
}

Weapon::~Weapon()
{
    std::cout << "Weapon destructor" << std::endl;
    return ;
}

void Weapon::setType(std::string new_type)
{
    this->_type = new_type;
    return ;
}

const std::string& Weapon::getType( void )
{
    const std::string  &type_ref = this->_type;
    return (type_ref);
}