/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:21:51 by vpf               #+#    #+#             */
/*   Updated: 2025/03/20 15:40:01 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define DEBUG   14287
#define INFO    9815
#define WARNING 27365
#define ERROR   15665

class Harl
{
    private:
        void    _debug( void );
        void    _info( void );
        void    _warning( void );
        void    _error( void );
    public:
        Harl();
        ~Harl();

        void    complain( std::string level );
        typedef void    (Harl::*function_t)( void );
};