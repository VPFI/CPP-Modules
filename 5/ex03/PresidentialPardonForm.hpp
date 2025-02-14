/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:13:46 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 14:44:04 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define PRESI_NAME "PresidentialPardonForm"
#define PRESI_SIGN 25
#define PRESI_EXEC 5

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string const   _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        PresidentialPardonForm(std::string target);
        virtual ~PresidentialPardonForm();

        PresidentialPardonForm &operator = (PresidentialPardonForm const &other);

        std::string const   &getTarget() const;

        virtual void        execute(Bureaucrat const &b) const;
};