/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:30:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/13 21:02:14 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat b1("11111", 75);
    Bureaucrat b2("22222", 75);

    try
    {
        while (true)
        {
            b1.incrementGrade();
            std::cout << b1 << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        while (true)
        {
            b2.decrementGrade();
            std::cout << b2 << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("33333", 0);
        while (true)
        {
            b3.incrementGrade();
            std::cout << b3 << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b4("44444", 151);
        while (true)
        {
            b4.decrementGrade();
            std::cout << b4 << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}