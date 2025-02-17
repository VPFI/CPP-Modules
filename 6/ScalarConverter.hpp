/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/17 21:51:51 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

enum    e_inputType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
}       t_input_type;

class ScalarConverter
{
    private:
        ScalarConverter();

    public:
        ~ScalarConverter();

        static void convert(std::string input);
};

