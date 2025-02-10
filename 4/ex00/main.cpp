/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:12:28 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 19:11:48 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Cat* c = new Cat();


    std::cout << std::endl << c->getType() << ": ";
    c->makeSound();
    std::cout << i->getType() << ": ";
    i->makeSound();
    std::cout << j->getType() << ": ";
    j->makeSound();
    std::cout << meta->getType() << ": ";
    meta->makeSound();

    std::cout << std::endl;

    delete (meta);
    delete (j);
    delete (i);
    delete (c);

    return 0;
}