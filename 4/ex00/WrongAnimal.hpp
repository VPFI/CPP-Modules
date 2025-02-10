/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:55:33 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 19:06:23 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        ~WrongAnimal();

        WrongAnimal &operator = (const WrongAnimal &other);

        std::string getType(void) const;
        void        setType(const std::string newType);

        void makeSound(void) const;
};