/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:49:33 by vpf               #+#    #+#             */
/*   Updated: 2025/02/13 02:50:20 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *_materiaInventory[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        virtual ~MateriaSource();

        MateriaSource &operator = (const MateriaSource &c);

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};