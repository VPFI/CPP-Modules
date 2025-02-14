/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:59:47 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 21:16:11 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
    std::cout
        << "Default Intern constructor called"
    << std::endl;

    return ;
}

Intern::Intern(const Intern &copy)
{
    std::cout
        << "Copy Intern constructor called"
    << std::endl;
    *this = copy;

    return ;
}

Intern::~Intern()
{
    std::cout
        << "Destructor Intern called"
    << std::endl;

    return ;
}

Intern &Intern::operator = (const Intern &other)
{
    std::cout
        << "Assignment copy Intern called"
    << std::endl;
    (void)other;

    return (*this);
}

const char *	Intern::FormNotFoundException::what(void) const throw()
{
    return ("Form not found | Invalid identifier");
}

static AForm   *makeShrubForm(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}
static AForm   *makeRoboForm(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}
static AForm   *makePresiForm(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeForm(std::string request, std::string target)
{
    try
    {
        AForm       *(*newForm[3])(const std::string &target) = { &makeShrubForm, &makeRoboForm, &makePresiForm };
        std::string requestNames[3] = {"shrubbery request", "robotomy request", "presidential request"};
        for (int i = 0; i < 3; i++)
        {
            if (request == requestNames[i])
            {
                return (newForm[i](target));
            }
        }
        throw(Intern::FormNotFoundException());
    }
    catch(const std::exception& e)
    {
        std::cerr
            << "Couldn't create form [" << request << "]"
            << "\n  Reason: " << e.what()
        << std::endl << std::endl;
    }
    return (NULL);
}
