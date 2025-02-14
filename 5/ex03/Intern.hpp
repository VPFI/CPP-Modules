/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:59:44 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 20:59:52 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:

    public:
        Intern();
        Intern(Intern const &copy);
        ~Intern();

        Intern &operator = (Intern const &other);

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        AForm   *makeForm(std::string request, std::string target);
};
