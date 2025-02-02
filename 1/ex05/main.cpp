/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:22:28 by vpf               #+#    #+#             */
/*   Updated: 2025/02/02 00:55:05 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{	
	Harl        harl;
    std::string input;

    while (getline(std::cin, input) && !(std::cin.eof()))
	{
        harl.complain(input);
    }
}