/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/03/06 20:31:50 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>

class RPN
{
	private:
		std::string				_input;

		std::string	getToken(size_t &pos, size_t &space) const;

		RPN();
		
	public:
		RPN(std::string const &stack);
		RPN(RPN const &copy);
		RPN &operator = (RPN const &other);

		~RPN();

		std::string	getInput(void) const;
		void    	calculate();

		class WrongInput : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
