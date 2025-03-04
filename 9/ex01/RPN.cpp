/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:34 by vpf               #+#    #+#             */
/*   Updated: 2025/03/04 18:12:13 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    return ;
}

RPN::RPN(std::string const &stack)
{
	loadStack(stack);

    return ;
}

RPN::RPN(RPN const &copy)
{
    (void)copy;

    return ;
}

RPN &RPN::operator = (RPN const &other)
{
    (void)other;

    return (*this);
}

RPN::~RPN()
{
    return ;
}

void    RPN::loadStack(std::string const &dbName)
{
	
}

void	RPN::printData()
{

}
