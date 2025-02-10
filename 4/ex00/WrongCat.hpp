/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:54:12 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 18:59:41 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    protected:

    public:
        WrongCat();
        WrongCat(const WrongCat &copy);
        ~WrongCat();

        WrongCat &operator = (const WrongCat &other);

        void makeSound(void) const;
};