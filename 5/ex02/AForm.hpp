/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:49:24 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 02:57:32 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const   _name;
        int const           _signReq;
        int const           _execReq;
        bool                _signed;

    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExec);
        AForm(AForm const &copy);
        virtual ~AForm();

        AForm &operator = (AForm const &other);
        friend std::ostream &operator << (std::ostream &out_s, const AForm &b);

        std::string const   &getName() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        bool                getSigned() const;

        void                beSigned(Bureaucrat const &b);
        virtual void                execute(Bureaucrat const &b) const = 0;

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

        class NotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
