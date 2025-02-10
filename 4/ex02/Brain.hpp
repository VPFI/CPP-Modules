/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:12:22 by vpf               #+#    #+#             */
/*   Updated: 2025/02/10 22:44:13 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Brain
{
    private:
        std::string _ideas[100];
     
    public:
        Brain();
        Brain(const Brain &copy);
        ~Brain();

        Brain &operator = (const Brain &other);
};

