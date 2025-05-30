/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:37:48 by vpf               #+#    #+#             */
/*   Updated: 2025/02/02 01:12:00 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

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
