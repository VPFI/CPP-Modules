/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:10:38 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 02:46:21 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define SHRUB_NAME "ShrubberyCreationForm"
#define SHRUB_SIGN 145
#define SHRUB_EXEC 137

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const   _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ShrubberyCreationForm(std::string target);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator = (ShrubberyCreationForm const &other);

        std::string const   &getTarget() const;

        virtual void        execute(Bureaucrat const &b) const;
};
