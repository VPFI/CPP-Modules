/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:49:21 by vpf               #+#    #+#             */
/*   Updated: 2025/04/01 16:01:05 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <iomanip>

AForm::AForm(): _name("Default"), _signReq(75), _execReq(75), _signed(false)
{
    std::cout
        << "Default Form constructor called"
    << std::endl;

    return ;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): _name(name),
    _signReq(gradeToSign), _execReq(gradeToExec), _signed(false)
{
    std::cout
        << "Name Form constructor called"
    << std::endl;
    if (gradeToSign > 150 || gradeToExec > 150)
    {
        throw(AForm::GradeTooLowException());
    }
    else if (gradeToSign < 1 || gradeToExec > 150)
    {
        throw(AForm::GradeTooHighException());
    }

    return ;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()),
    _signReq(copy.getSignGrade()), _execReq(copy.getExecGrade()), _signed(copy.getSigned())
{
    std::cout
        << "Copy Form constructor called"
    << std::endl;

    return ;
}

AForm::~AForm()
{
    std::cout
        << "Destructor Form called"
    << std::endl;

    return ;
}

AForm &AForm::operator = (const AForm &other)
{
    std::cout
        << "Assignment copy Form called"
    << std::endl;
    if (this != &other)
    {
        this->_signed = other.getSigned(); // doesn't make much sense
    }
    return (*this);
}

std::ostream &operator << (std::ostream &out_s, const AForm &Aform)
{
	return (out_s << std::endl << std::setw(35) << std::setfill('-') << "|"
        << "\nForm name: " << Aform.getName()
        << "\n  Grade requirement to sign: " << Aform.getSignGrade()
        << "\n  Grade requirement to execute: " << Aform.getExecGrade()
        << "\n  Signed status: "<< (Aform.getSigned() ? "true" : "false")
        << std::endl << std::setw(35) << "|" << std::endl);
}

const char  *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low | ");
}

const char  *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high | ");
}

const char  *AForm::NotSignedException::what(void) const throw()
{
    return ("Form not signed | ");
}

std::string const   &AForm::getName() const
{
    return (this->_name);
}

int AForm::getSignGrade() const
{
    return (this->_signReq);
}

int AForm::getExecGrade() const
{
    return (this->_execReq);
}

bool AForm::getSigned() const
{
    return (this->_signed);
}

void    AForm::beSigned(Bureaucrat const &b)
{
    if (this->_signReq < b.getGrade())
        throw(AForm::GradeTooLowException());
    else
    {
        this->_signed = true;
    }
}
