/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:22:25 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 02:58:29 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <iomanip>

PresidentialPardonForm::PresidentialPardonForm() : AForm(PRESI_NAME, PRESI_SIGN, PRESI_EXEC), _target("default")
{
    std::cout
        << "Default Form constructor called"
    << std::endl;

    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(PRESI_NAME, PRESI_SIGN, PRESI_EXEC), _target(target)
{
    std::cout
        << "Name Form constructor called"
    << std::endl;
    // if (gradeToSign > 150 || gradeToExec > 150)
    // {
    //     throw(PresidentialPardonForm::GradeTooLowException());
    // }
    // else if (gradeToSign < 1 || gradeToExec > 150)
    // {
    //     throw(PresidentialPardonForm::GradeTooHighException());
    // }

    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade()),
    _target(copy.getTarget())
{
    std::cout
        << "Copy Form constructor called"
    << std::endl;

    return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout
        << "Destructor Form called"
    << std::endl;

    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &other)
{
    std::cout
        << "Assignment copy Form called"
    << std::endl;
    (void)other;

    // doesn't make much sense
    return (*this);
}

std::string const   &PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void       PresidentialPardonForm::execute(Bureaucrat const &b) const
{
    if (this->getSigned() == false)
        throw(AForm::NotSignedException());
    if (this->getExecGrade() < b.getGrade())
        throw(AForm::GradeTooLowException());
    else
    {
        std::cout << "PRESI executed" << std::endl;
    }
}
