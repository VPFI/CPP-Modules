/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:14:45 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 17:47:23 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SHRUB_NAME, SHRUB_SIGN, SHRUB_EXEC), _target("default")
{
    std::cout
        << "Default SHRUB-Form constructor called"
    << std::endl;

    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(SHRUB_NAME, SHRUB_SIGN, SHRUB_EXEC), _target(target)
{
    std::cout
        << "Name SHRUB-Form constructor called"
    << std::endl;

    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy.getTarget())
{
    std::cout
        << "Copy SHRUB-Form constructor called"
    << std::endl;

    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout
        << "Destructor SHRUB-Form called"
    << std::endl;

    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other)
{
    std::cout
        << "Assignment copy SHRUB-Form called"
    << std::endl;
    (void)other;

    // doesn't make much sense
    return (*this);
}

std::string const   &ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

static void    formAction(std::string target)
{
    std::ofstream outFile;

    outFile.open((target + "_shrubbery").c_str(), std::ios::trunc);
    if (!outFile.is_open())
        throw(std::runtime_error(std::string("Failed to open: ") + target));
    for (int i = 1; i <= 10; ++i)
    {
        for (int j = 0; j < 10 - i; ++j)
            outFile << " ";
        for (int j = 0; j < 2 * i - 1; ++j)
            outFile << "*";

        outFile << std::endl;
    }
    for (int i = 0; i < 10 / 3; ++i)
    {
        for (int j = 0; j < 10 - 1; ++j)
            outFile << " ";
        outFile << "||" << std::endl;
    }
    outFile.close();
}

void    ShrubberyCreationForm::execute(Bureaucrat const &b) const
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
