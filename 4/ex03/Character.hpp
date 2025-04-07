/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:41:05 by vpf               #+#    #+#             */
/*   Updated: 2025/03/24 18:57:19 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iomanip>
#include "ICharacter.hpp"

#define COL_WIDTH 20

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria    *_materiaInventory[4];

    public:
        Character();
        Character(const Character &copy);
        Character(std::string const & name);
        ~Character();

        Character &operator = (const Character &c);

        virtual std::string const & getName() const;

        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};