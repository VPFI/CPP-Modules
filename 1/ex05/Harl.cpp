/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:37:11 by vpf               #+#    #+#             */
/*   Updated: 2025/02/02 01:18:54 by vpf              ###   ########.fr       */
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
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    function_t  funcs[] = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };

    for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			break ;
		}
        if (i == 3)
		    std::cout << "Unknown error..." << std::endl;
	}
}

void	Harl::_debug(void)
{	
	std::cout
        << "[DEBUG] I love having extra bacon for my 7XL-double-cheese"
        << "-triple-pickle-specialketchup burger. I really do!"
    << std::endl;
}

void	Harl::_info(void)
{
	std::cout
        << "[INFO] I cannot believe adding extra bacon costs more money. "
	    << "You didn't put enough bacon in my burger! If you did, "
	    << "I wouldn't be asking for more!"
    << std::endl;
}

void	Harl::_warning(void)
{
	std::cout
        << "[WARNING] I think I deserve to have some extra bacon for free. "
	    << "I've been coming for years whereas you started working here since last month."
	<< std::endl;
}

void	Harl::_error(void)
{
	std::cout
        << "[ERROR] This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}
