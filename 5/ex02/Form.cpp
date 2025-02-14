/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:03:33 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 01:35:13 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <iomanip>

Form::Form(): _name("Default"), _signReq(75), _execReq(75), _signed(false)
{
    std::cout
        << "Default Form constructor called"
    << std::endl;

    return ;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name),
    _signReq(gradeToSign), _execReq(gradeToExec), _signed(false)
{
    std::cout
        << "Name Form constructor called"
    << std::endl;
    if (gradeToSign > 150 || gradeToExec > 150)
    {
        throw(Form::GradeTooLowException());
    }
    else if (gradeToSign < 1 || gradeToExec > 150)
    {
        throw(Form::GradeTooHighException());
    }

    return ;
}

Form::Form(const Form &copy) : _name(copy.getName()),
    _signReq(copy.getSignGrade()), _execReq(getExecGrade()), _signed(copy.getSigned())
{
    std::cout
        << "Copy Form constructor called"
    << std::endl;

    return ;
}

Form::~Form()
{
    std::cout
        << "Destructor Form called"
    << std::endl;

    return ;
}

Form &Form::operator = (const Form &other)
{
    std::cout
        << "Assignment copy Form called"
    << std::endl;
    if (this != &other)
    {
        this->_signed = other._signed; // doesn't make much sense
    }
    return (*this);
}

std::ostream &operator << (std::ostream &out_s, const Form &form)
{
	return (out_s << std::endl << std::setw(35) << std::setfill('-') << "|"
        << "\nForm name: " << form.getName()
        << "\n  Grade requirement to sign: " << form.getSignGrade()
        << "\n  Grade requirement to execute: " << form.getExecGrade()
        << "\n  Signed status: "<< (form.getSigned() ? "true" : "false")
        << std::endl << std::setw(35) << "|" << std::endl);
}

const char  *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low.");
}

const char  *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high.");
}

std::string const   &Form::getName() const
{
    return (this->_name);
}

int Form::getSignGrade() const
{
    return (this->_signReq);
}

int Form::getExecGrade() const
{
    return (this->_execReq);
}

bool Form::getSigned() const
{
    return (this->_signed);
}

void    Form::beSigned(Bureaucrat const &b)
{
    if (this->_signReq < b.getGrade())
        throw(Bureaucrat::GradeTooLowException());
    else
    {
        this->_signed = true;
    }
}
