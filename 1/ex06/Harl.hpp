/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:21:51 by vpf               #+#    #+#             */
/*   Updated: 2025/02/02 01:39:49 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define DEBUG   359
#define INFO    300
#define WARNING 534
#define ERROR   394

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