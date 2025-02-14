/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:22:42 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 02:58:26 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <iomanip>

RobotomyRequestForm::RobotomyRequestForm() : AForm(ROBO_NAME, ROBO_SIGN, ROBO_EXEC), _target("default")
{
    std::cout
        << "Default Form constructor called"
    << std::endl;

    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(ROBO_NAME, ROBO_SIGN, ROBO_EXEC), _target(target)
{
    std::cout
        << "Name Form constructor called"
    << std::endl;
    // if (gradeToSign > 150 || gradeToExec > 150)
    // {
    //     throw(RobotomyRequestForm::GradeTooLowException());
    // }
    // else if (gradeToSign < 1 || gradeToExec > 150)
    // {
    //     throw(RobotomyRequestForm::GradeTooHighException());
    // }

    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade()),
    _target(copy.getTarget())
{
    std::cout
        << "Copy Form constructor called"
    << std::endl;

    return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout
        << "Destructor Form called"
    << std::endl;

    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &other)
{
    std::cout
        << "Assignment copy Form called"
    << std::endl;
    (void)other;
    // doesn't make much sense
    return (*this);
}

std::string const   &RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

void       RobotomyRequestForm::execute(Bureaucrat const &b) const
{
    if (this->getSigned() == false)
        throw(AForm::NotSignedException());
    if (this->getExecGrade() < b.getGrade())
        throw(AForm::GradeTooLowException());
    else
    {
        std::cout << "ROBOT executed" << std::endl;
    }
}
