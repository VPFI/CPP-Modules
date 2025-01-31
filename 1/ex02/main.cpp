/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:39:26 by vperez-f          #+#    #+#             */
/*   Updated: 2025/01/31 20:48:02 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "Str mem address: " << &str << std::endl;
	std::cout << "Ptr mem address: " << ptr << std::endl;
	std::cout << "Ref mem address: " << &ref << std::endl;

	std::cout << "Str val: " << str << std::endl;
	std::cout << "Ptr val: " << *ptr << std::endl;
	std::cout << "Ref val: " << ref << std::endl;
}