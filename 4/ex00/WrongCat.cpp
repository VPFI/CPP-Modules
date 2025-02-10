/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:12:33 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 18:59:27 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout
        << "Default WrongCat constructor called"
    << std::endl;
    this->setType("WrongCat");

    return ;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout
        << "Copy WrongCat constructor called"
    << std::endl;
    *this = copy;

    return ;
}

WrongCat::~WrongCat()
{
    std::cout
        << "WrongCat destructor called"
    << std::endl;

    return ;
}

WrongCat &WrongCat::operator = (const WrongCat &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout
        << "MIAUUUUUU"
    << std::endl;

    return ;
}
