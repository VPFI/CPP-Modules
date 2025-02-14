/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:22:25 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 17:38:46 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(PRESI_NAME, PRESI_SIGN, PRESI_EXEC), _target("default")
{
    std::cout
        << "Default PRES-Form constructor called"
    << std::endl;

    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(PRESI_NAME, PRESI_SIGN, PRESI_EXEC), _target(target)
{
    std::cout
        << "Name PRES-Form constructor called"
    << std::endl;

    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy.getTarget())
{
    std::cout
        << "Copy PRES-Form constructor called"
    << std::endl;

    return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout
        << "Destructor PRES-Form called"
    << std::endl;

    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &other)
{
    std::cout
        << "Assignment copy PRES-Form called"
    << std::endl;
    (void)other;

    // doesn't make much sense
    return (*this);
}

std::string const   &PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

static void    formAction(std::string target)
{
    std::cout << target << " has been pardoned by President Zaphod Beeblebrox" << std::endl;

    return ;
}

void    PresidentialPardonForm::execute(Bureaucrat const &b) const
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
