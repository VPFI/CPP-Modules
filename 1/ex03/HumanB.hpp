/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:26:38 by vpf               #+#    #+#             */
/*   Updated: 2025/02/01 17:55:16 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon      *_weapon = NULL;
        
    public:
        HumanB(std::string name);
        ~HumanB();

        void    setWeapon(Weapon &newWeapon);
        void    attack( void );
};
