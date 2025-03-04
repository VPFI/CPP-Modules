/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/03/04 15:36:47 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BitcoinExchange &btc = BitcoinExchange::getInstance();
	if (argc == 1)
    	btc.printData();
	else if (argc == 2)
	{
		btc.customDataInput(argv[1]);
	}
	else
		std::cout << "Wrong number of arguments || ./btc [optional input.txt] --> Date | value-modifier" << std::endl;

    return (0);
}
