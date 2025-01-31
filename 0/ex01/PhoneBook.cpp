/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:01:36 by vperez-f          #+#    #+#             */
/*   Updated: 2025/01/29 16:20:15 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook()
{
	this->_current_amount = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::close(int exit_code)
{
	exit(exit_code);
}

int	PhoneBook::print_available_commands()
{
	std::cout << "\nAvailable commands:\n";
	std::cout << "\nADD: ";
	std::cout << "adds a new contact to the book, all required information must be provided";
	std::cout << "\nSEARCH: ";
	std::cout << "lists a specific contact";
	std::cout << "\nEXIT: ";
	std::cout << "quits the program entirely losing all contacts" << std::endl << std::endl;
	return (1);
}

void	PhoneBook::_print_contact(std::string input)
{
	int	index;

	if (input.size() != 1 || isdigit(input[0]) == false)
	{
		std::cout << std::endl << "Wrong contact index: " << input << std::endl;
		return ;
	}
	index = atoi(input.c_str());
	if (0 <= index && index < this->_current_amount)
	{
		std::cout << std::endl << "Contact #" << index << ":" << std::endl;
		std::cout << this->_contacts[index].get_first_name() << std::endl;
		std::cout << this->_contacts[index].get_last_name() << std::endl;
		std::cout << this->_contacts[index].get_nickname() << std::endl;
		std::cout << this->_contacts[index].get_phone_number() << std::endl;
		std::cout << this->_contacts[index].get_darkest_secret() << std::endl;
	}
	else
		std::cout << std::endl << "Contact #" << index << " not found" << std::endl;
}

static std::string	truncate_str(std::string str)
{
	if (str.size() < 10)
		return (str);
	else
	{
		return (str.substr(0, 9) + '.');
	}
}

int	PhoneBook::print_all_contacts(void)
{
	std::cout << "\nThese are your current contacts:\n";
	if (this->_current_amount <= 0)
	{
		std::cout << "    --- No contacts found ---\n";
		return (1);
	}
	else
	{
		std::cout << std::setw(10) << std::right << "    FirstName |";
		std::cout << std::setw(10) << std::right << " LastName |";
		std::cout << std::setw(10) << std::right << " NickName |";
		std::cout << std::setw(10) << std::right << " Phone Number";
		for (int i = 0; i < this->_current_amount; i++)
		{
			std::cout << std::endl << "#[" << i << "]";
			std::cout << std::setw(10) << std::right << truncate_str(this->_contacts[i].get_first_name()) << "|";
			std::cout << std::setw(10) << std::right << truncate_str(this->_contacts[i].get_last_name()) << "|";
			std::cout << std::setw(10) << std::right << truncate_str(this->_contacts[i].get_nickname()) << "|";
			std::cout << std::setw(10) << std::right << truncate_str(this->_contacts[i].get_phone_number());
		}
	}
	std::cout << std::endl;
	return (0);
}

int	PhoneBook::_get_oldest_contact_index(void)
{
	int index = 0;
	std::time_t time;

	if (this->_current_amount <= 0)
	{
		return (-1);
	}
	time = this->_contacts[0].get_time();
	for (int i = 0, c = this->_current_amount; i < c; i++)
	{
		if (this->_contacts[i].get_time() < time)
		{
			time = this->_contacts[i].get_time();		
			index = i;
		}
	}
	return (index);
}

void	PhoneBook::add_contact(void)
{
	if (this->_current_amount < 8)
	{
		this->_contacts[_current_amount].init_contact();
		this->_current_amount++;
	}
	else
	{
		int	oldest_index = this->_get_oldest_contact_index();
		this->_contacts[oldest_index].init_contact();
	}
	std::cout << "Contact added succesfully!" << std::endl << std::endl;
	return ;
}

void	PhoneBook::search_contact(void)
{
	std::string	index;

	if (this->print_all_contacts())
		return ;
	std::cout << std::endl << "Type the index of the contact you want to display" << std::endl;
	getline(std::cin, index);
	if (std::cin.eof())
		exit (1);
	this->_print_contact(index);
	return ;
}
