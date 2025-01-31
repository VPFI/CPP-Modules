/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:08:53 by vperez-f          #+#    #+#             */
/*   Updated: 2025/01/29 16:22:45 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	p_book;
	std::string	input;

	std::cout << "--| Welcome to your contacts list! |--" << std::endl;
	p_book.print_all_contacts();
	while (p_book.print_available_commands() && getline(std::cin, input) && !(std::cin.eof()))
	{
		if (input == "EXIT" || input =="exit")
		{
			p_book.close(0);
		}
		else if (input == "ADD" || input =="add")
		{
			p_book.add_contact();
		}
		else if (input == "SEARCH" || input =="search")
		{
			p_book.search_contact();
		}
		else
		{
			std::cout << "Unknown command...\n";
		}
	}
}
