/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/03/06 20:31:50 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <vector>
#include <iostream>

class PmergeMe
{
	private:
		std::vector<unsigned int>	_input;
		
	public:
		PmergeMe();
		PmergeMe(std::vector<unsigned int> const &stack);
		PmergeMe(PmergeMe const &copy);

		PmergeMe &operator = (PmergeMe const &other);

		~PmergeMe();

		std::vector<unsigned int>	getInput() const;
		void    					sort();

		class WrongInput : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
