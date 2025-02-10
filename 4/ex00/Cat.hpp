/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:12:31 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 18:48:46 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    protected:

    public:
        Cat();
        Cat(const Cat &copy);
        ~Cat();

        Cat &operator = (const Cat &other);

        void makeSound(void) const;
};