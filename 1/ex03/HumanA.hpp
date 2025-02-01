/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:18:33 by vpf               #+#    #+#             */
/*   Updated: 2025/02/01 17:51:56 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon      &_weapon;

    public:
        HumanA(std::string name, Weapon &newWeapon);
        ~HumanA();

        void    attack( void );
};
