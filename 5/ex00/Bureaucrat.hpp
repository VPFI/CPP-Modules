/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:48:17 by vpf               #+#    #+#             */
/*   Updated: 2025/02/13 20:42:45 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>

class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        ~Bureaucrat();

        Bureaucrat &operator = (Bureaucrat const &other);
        friend std::ostream &operator << (std::ostream &out_s, const Bureaucrat &b);

        std::string const   &getName() const;
        int                 getGrade() const;

        void                incrementGrade();
        void                decrementGrade();

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
