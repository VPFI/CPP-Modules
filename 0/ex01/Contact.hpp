/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:57:46 by vperez-f          #+#    #+#             */
/*   Updated: 2025/01/29 15:06:56 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <ctime>
#include <string>

#define FIRST_NAME "Please input first name:"
#define LAST_NAME "Please input last name:"
#define NICKNAME "Please input nickname:"
#define PHONE_NUMBER "Please input phone number (only numbers allowed):"
#define DARKEST_SECRET "Please input darkest secret:"

class Contact
{
	private:
		std::time_t	_date_added;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

		void	_set_time(void);
		void	_set_first_name(std::string content);
		void	_set_last_name(std::string content);
		void	_set_nickname(std::string content);
		void	_set_phone_number(std::string content);
		void	_set_darkest_secret(std::string content);

		int		_set_field(int field_index, std::string content);
	public:
		Contact();
		~Contact();

		std::time_t	get_time(void);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);

		void	init_contact();
};

#endif