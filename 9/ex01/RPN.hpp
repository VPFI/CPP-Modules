/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/03/04 19:32:03 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<float> _stack;

        void    	loadStack(std::string const &dbName);
		RPN();
        
    public:
		RPN(std::string const &stack);
        RPN(RPN const &copy);
        RPN &operator = (RPN const &other);

        ~RPN();

        void    printData();
};
