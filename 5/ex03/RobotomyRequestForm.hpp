/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:12:27 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 15:19:32 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <cmath>
#include <string>
#include <iomanip>
#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define ROBO_NAME "RobotomyRequestForm"
#define ROBO_SIGN 72
#define ROBO_EXEC 45

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string const   _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        RobotomyRequestForm(std::string target);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm &operator = (RobotomyRequestForm const &other);

        std::string const   &getTarget() const;

        virtual void        execute(Bureaucrat const &b) const;
};
