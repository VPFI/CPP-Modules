/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/03/06 23:43:04 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments || ./rpn \"1 2 + 2 - 3 * 2 /\"" << std::endl;
		return (1);
	}
	
	try
	{
		RPN	calc(argv[1]);
		// RPN	calc("-13 2 + 3 43 + /");
		calc.calculate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    return (0);
}
