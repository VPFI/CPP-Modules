/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:28:36 by vperez-f          #+#    #+#             */
/*   Updated: 2025/01/29 15:29:40 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>


Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

//--------------------------------------------------------//

std::string	Contact::get_first_name(void)
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void)
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void)
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->_darkest_secret);
}

void	Contact::_set_first_name(std::string content)
{
	this->_first_name = content;
	return ;
}

void	Contact::_set_last_name(std::string content)
{
	this->_last_name = content;
	return ;
}

void	Contact::_set_nickname(std::string content)
{
	this->_nickname = content;
	return ;
}

void	Contact::_set_phone_number(std::string content)
{
	this->_phone_number = content;
	return ;
}

void	Contact::_set_darkest_secret(std::string content)
{
	this->_darkest_secret = content;
	return ;
}

std::time_t	Contact::get_time(void)
{
	return (this->_date_added);
}

void	Contact::_set_time(void)
{
	this->_date_added = time(NULL);
	return ;
}

//-----------------------------------------------------------------//


int static	check_numbers(std::string s)
{
	for (std::string::size_type i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			return (1);
		}
	}
	return (0);
}

int static	invalid_string(std::string s)
{
	if (s.empty())
	{
		return (1);
	}
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!isalnum(s[i]))
		{
			return (1);
		}
	}
	return (0);
}

int	Contact::_set_field(int field_index, std::string content)
{
	if (invalid_string(content))
		return (1);
	if (field_index == 0)
		_set_first_name(content);
	else if (field_index == 1)
		_set_last_name(content);
	else if (field_index == 2)
		_set_nickname(content);
	else if (field_index == 3)
	{
		if (check_numbers(content))
			return (1);
		_set_phone_number(content);
	}
	else if (field_index == 4)
		_set_darkest_secret(content);
	else
		return (1);
	return (0);
}

static int	print_contact_message(int index)
{
	if (index == 0)
		std::cout << FIRST_NAME << std::endl;
	else if (index == 1)
		std::cout << LAST_NAME << std::endl;
	else if (index == 2)
		std::cout << NICKNAME << std::endl;
	else if (index == 3)
		std::cout << PHONE_NUMBER << std::endl;
	else if (index == 4)
		std::cout << DARKEST_SECRET << std::endl;
	else
		return (1);
	return (0);	
}

#include <cstdlib>

void	Contact::init_contact()
{
	int			index = 0;
	std::string	input;

	print_contact_message(index);
	while (index < 5 && getline(std::cin, input) && !(std::cin.eof()))
	{
		if (this->_set_field(index, input))
		{
			std::cout << "Bad input, please try again..." << std::endl;
			print_contact_message(index);
			continue ;	
		}
		index++;
		print_contact_message(index);
	}
	if (std::cin.eof())
		exit (1);
	this->_date_added = time(NULL);
}
