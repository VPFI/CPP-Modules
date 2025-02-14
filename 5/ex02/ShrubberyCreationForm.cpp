/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:14:45 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 02:58:22 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <iomanip>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SHRUB_NAME, SHRUB_SIGN, SHRUB_EXEC), _target("default")
{
    std::cout
        << "Default Form constructor called"
    << std::endl;

    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(SHRUB_NAME, SHRUB_SIGN, SHRUB_EXEC), _target(target)
{
    std::cout
        << "Name Form constructor called"
    << std::endl;
    // if (gradeToSign > 150 || gradeToExec > 150)
    // {
    //     throw(ShrubberyCreationForm::GradeTooLowException());
    // }
    // else if (gradeToSign < 1 || gradeToExec > 150)
    // {
    //     throw(ShrubberyCreationForm::GradeTooHighException());
    // }

    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade()),
    _target(copy.getTarget())
{
    std::cout
        << "Copy Form constructor called"
    << std::endl;

    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout
        << "Destructor Form called"
    << std::endl;

    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other)
{
    std::cout
        << "Assignment copy Form called"
    << std::endl;
    (void)other;

    // doesn't make much sense
    return (*this);
}

std::string const   &ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void       ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
    if (this->getSigned() == false)
        throw(AForm::NotSignedException());
    else if (this->getExecGrade() < b.getGrade())
        throw(AForm::GradeTooLowException());
    else
    {
        std::cout << "SHRUB executed" << std::endl;
    }
}
