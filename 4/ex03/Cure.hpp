/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:39:41 by vpf               #+#    #+#             */
/*   Updated: 2025/02/12 22:39:12 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
    private:

    public:
        Cure();
        Cure(const Cure &copy);
        ~Cure();

        Cure &operator = (const Cure &c);
        
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};


