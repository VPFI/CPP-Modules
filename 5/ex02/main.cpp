/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:30:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 17:39:18 by vpf              ###   ########.fr       */
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
    AForm       *f1 = new ShrubberyCreationForm("TREE");
    AForm       *f2 = new RobotomyRequestForm("SUBJECT");
    AForm       *f3 = new PresidentialPardonForm("ACCUSED");

    std::cout << std::endl;
    b2.signForm(*f1);
    b1.executeForm(*f1);
    b1.signForm(*f1);
    std::cout << *f1 << std::endl;
    b2.executeForm(*f1);
    b1.executeForm(*f1);
    std::cout << std::endl;

    b2.signForm(*f2);
    b1.executeForm(*f2);
    b1.signForm(*f2);
    std::cout << *f2 << std::endl;
    b2.executeForm(*f2);
    b1.executeForm(*f2);
    std::cout << std::endl;

    b2.signForm(*f3);
    b1.executeForm(*f3);
    b1.signForm(*f3);
    std::cout << *f3 << std::endl;
    b2.executeForm(*f3);
    b1.executeForm(*f3);
    std::cout << std::endl;

    delete (f1);
    delete (f2);
    delete (f3);
}