/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:03:05 by vperez-f          #+#    #+#             */
/*   Updated: 2025/01/27 17:00:15 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++)			
				std::cout << (char)toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
}
