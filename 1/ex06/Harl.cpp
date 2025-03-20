/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:21:42 by vpf               #+#    #+#             */
/*   Updated: 2025/03/20 15:40:45 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    return ;
}

Harl::~Harl(void)
{
    return ;
}

void    Harl::complain(std::string level)
{
    size_t  sum = 0;

    for (size_t i = 0; i < level.size(); i++) {sum += (level[i] * (13 * (i + 1)));};
    switch (sum)
    {
        case (DEBUG):
            this->_debug();
            //FALLTHROUGH
        case (INFO):
            this->_info();
            //FALLTHROUGH
        case (WARNING):
            this->_warning();
            //FALLTHROUGH
        case (ERROR):
            this->_error();
            break;

        default:
            std::cout
                << "[ Probably complaining about insignificant problems ]"
            << std::endl;
            break;
    }
}

void	Harl::_debug(void)
{	
	std::cout
        << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese"
        << "-triple-pickle-specialketchup burger. I really do!"
    << std::endl;
}

void	Harl::_info(void)
{
	std::cout
        << "[INFO]\nI cannot believe adding extra bacon costs more money. "
	    << "You didn't put enough bacon in my burger! If you did, "
	    << "I wouldn't be asking for more!"
    << std::endl;
}

void	Harl::_warning(void)
{
	std::cout
        << "[WARNING]\nI think I deserve to have some extra bacon for free. "
	    << "I've been coming for years whereas you started working here since last month."
	<< std::endl;
}

void	Harl::_error(void)
{
	std::cout
        << "[ERROR]\nThis is unacceptable! I want to speak to the manager now."
	<< std::endl;
}
