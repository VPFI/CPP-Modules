/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:17 by vpf               #+#    #+#             */
/*   Updated: 2025/02/17 21:56:25 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    return ;
}

ScalarConverter::~ScalarConverter()
{
    return ;
}

static void    convertToChar(std::string &input)
{

}

static void    convertToInt(std::string &input)
{

}

static void    convertToFloat(std::string &input)
{

}

static void    convertToDouble(std::string &input)
{

}


static int    detectNativeType(std::string &input)
{
    
}


void convert(std::string input)
{
    int type;

    if (input.empty())
        return ;
    type = detectNativeType(input);
    switch (type)
    {
        case(CHAR):
            convertToChar(input);
            break;
        case(INT):
            convertToInt(input);
            break;
        case(FLOAT):
            convertToFloat(input);
            break;
        case(DOUBLE):
            convertToDouble(input);
            break;
    
        default:
            break;
    }
}
