/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:39:08 by vpf               #+#    #+#             */
/*   Updated: 2025/02/12 22:39:16 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
    private:

    public:
        Ice();
        Ice(const Ice &copy);
        ~Ice();

        Ice &operator = (const Ice &c);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};