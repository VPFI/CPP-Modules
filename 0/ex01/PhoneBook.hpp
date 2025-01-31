/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:01:46 by vperez-f          #+#    #+#             */
/*   Updated: 2025/01/29 16:20:20 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		int		_current_amount;
		Contact _contacts[8];

		int		_get_oldest_contact_index(void);
		void	_print_contact(std::string input);
	public:
		PhoneBook();
		~PhoneBook();

		void	add_contact(void);
		void	search_contact(void);
		int		print_all_contacts(void);
		int		print_available_commands(void);
		void	close(int exit_code);
};

#endif