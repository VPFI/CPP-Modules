/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:10:21 by vpf               #+#    #+#             */
/*   Updated: 2025/02/01 17:09:11 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class   Weapon
{
    private:
        std::string _type;
        
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();

        const std::string& getType( void );
        void setType(std::string new_type);
};
