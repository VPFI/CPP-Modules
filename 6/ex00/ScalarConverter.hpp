/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/20 16:05:37 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstring>
#include <cstdlib>
#include <string>
#include <limits>
#include <iostream>
#include <iomanip>

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

