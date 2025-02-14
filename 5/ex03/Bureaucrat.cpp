/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:48:09 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 17:25:43 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): _name("Default"), _grade(75)
{
    std::cout
        << "Default Bureaucrat constructor called"
    << std::endl;

    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    std::cout
        << "Name Bureaucrat constructor called"
    << std::endl;
    if (grade > 150)
    {
        throw(Bureaucrat::GradeTooLowException());
    }
    else if (grade < 1)
    {
        throw(Bureaucrat::GradeTooHighException());
    }
    this->_grade = grade;

    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
    std::cout
        << "Copy Bureaucrat constructor called"
    << std::endl;
    *this = copy;

    return ;
}

Bureaucrat::~Bureaucrat()
{
    std::cout
        << "Destructor Bureaucrat called"
    << std::endl;

    return ;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other)
{
    std::cout
        << "Assignment copy Bureaucrat called"
    << std::endl;
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}

std::ostream &operator << (std::ostream &out_s, const Bureaucrat &b)
{
	return (out_s << "Bureaucrat "<< b.getName() << " of Grade " << b.getGrade());
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low -- [1 - 150]");
}

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high -- [1 - 150]");
}

std::string const   &Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
        throw(Bureaucrat::GradeTooHighException());
    this->_grade--;

    return ;
}

void    Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
        throw(Bureaucrat::GradeTooLowException());
    this->_grade++;

    return ;
}

void    Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout
            << *this
            << " signed form: "
            << form.getName()
        << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr
            << *this << " couldn't sign form: " << form.getName()
            << "\n  Reason: " << e.what()
            << "Form requirement: Grade " << form.getSignGrade()
        << std::endl << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout
            << *this
            << " executed form: "
            << form.getName()
        << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr
            << *this << " couldn't execute form: " << form.getName()
            << "\n  Reason: " << e.what()
            << "Form requirement: Grade " << form.getExecGrade()
        << std::endl << std::endl;
    }
}
