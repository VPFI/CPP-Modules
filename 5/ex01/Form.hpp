/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:03:24 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 00:57:14 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        int const           _signReq;
        int const           _execReq;
        bool                _signed;

    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(Form const &copy);
        ~Form();

        Form &operator = (Form const &other);
        friend std::ostream &operator << (std::ostream &out_s, const Form &b);

        std::string const   &getName() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        bool                getSigned() const;

        void                beSigned(Bureaucrat const &b);

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
