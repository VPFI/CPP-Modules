/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:22:42 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 17:39:02 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(ROBO_NAME, ROBO_SIGN, ROBO_EXEC), _target("default")
{
    std::cout
        << "Default ROBO-Form constructor called"
    << std::endl;

    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(ROBO_NAME, ROBO_SIGN, ROBO_EXEC), _target(target)
{
    std::cout
        << "Name ROBO-Form constructor called"
    << std::endl;

    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy.getTarget())
{
    std::cout
        << "Copy ROBO-Form constructor called"
    << std::endl;

    return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout
        << "Destructor ROBO-Form called"
    << std::endl;

    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &other)
{
    std::cout
        << "Assignment copy ROBO-Form called"
    << std::endl;
    (void)other;
    // doesn't make much sense
    return (*this);
}

std::string const   &RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

static void    formAction(std::string target)
{
    std::cout << "*** LOUD DRILLING NOISES ***" << std::endl;
    if ((rand() / (float)RAND_MAX) < 0.5)
        std::cout << "*** " << target << " has been succesfully robotomized  ***" << std::endl;
    else
        std::cout << "***  Robotomization failed! :(  ***" << std::endl;

    return ;
}

void    RobotomyRequestForm::execute(Bureaucrat const &b) const
{
    if (this->getSigned() == false)
        throw(AForm::NotSignedException());
    if (this->getExecGrade() < b.getGrade())
        throw(AForm::GradeTooLowException());
    else
    {
        formAction(this->_target);
    }
}
