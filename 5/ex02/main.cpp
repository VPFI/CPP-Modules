/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:30:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 03:03:22 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat  b1("11111", 1);
    Bureaucrat  b2("22222", 150);
    AForm        *f1 = new ShrubberyCreationForm("TESTTARGET");

    std::cout << std::endl;
    b2.signForm(*f1);
    b2.executeForm(*f1);
    std::cout << *f1 << std::endl;
    b1.signForm(*f1);
    std::cout << *f1 << std::endl;
    b1.executeForm(*f1);

    delete (f1);
}