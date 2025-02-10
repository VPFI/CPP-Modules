/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:12:35 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 18:48:49 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    protected:

    public:
        Dog();
        Dog(const Dog &copy);
        ~Dog();

        Dog &operator = (const Dog &other);

        void makeSound(void) const;
};