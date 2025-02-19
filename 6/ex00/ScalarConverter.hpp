/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/19 23:24:04 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstring>
#include <cstdlib>
#include <string>
#include <limits>
#include <iostream>

enum    e_inputType
{
    CHAR_E,
    INT_E,
    FLOAT_E,
    DOUBLE_E,
    UNDEFINED_E
};

class ScalarConverter
{
    private:
        ScalarConverter();

    public:
        ~ScalarConverter();

        static void convert(std::string input);
};

