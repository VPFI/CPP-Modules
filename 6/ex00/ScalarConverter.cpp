/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:17 by vpf               #+#    #+#             */
/*   Updated: 2025/02/19 23:25:45 by vpf              ###   ########.fr       */
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

static void    convertToChar(std::string &input, int type)
{
    if (type == CHAR_E)
    {
        std::cout << "char: " << input << std::endl;
        return ;        
    }
    else
        std::cout << "char: " << static_cast<unsigned char>(std::atoi(input.c_str())) << std::endl;
}

static void    convertToInt(std::string &input, int type)
{
    if (type == INT_E)
    {
        std::cout << "int: " << input << std::endl;
        return ;        
    }
    else
        std::cout << "char: " << std::atoi(input.c_str()) << std::endl;
}

static void    convertToFloat(std::string &input, int type)
{
    if (type == FLOAT_E)
    {
        std::cout << "float: " << input << std::endl;
        return ;        
    }
    else
        std::cout << "float: " << std::atof(input.c_str()) << "f" << std::endl;
}

static void    convertToDouble(std::string &input, int type)
{
    if (type == DOUBLE_E)
    {
        std::cout << "double: " << input << std::endl;
        return ;        
    }
    else
        std::cout << "double: " << static_cast<double>(std::atof(input.c_str())) << std::endl;
}


static int    detectNativeType(std::string &input)
{
    int             decimal = 0;
    int             f       = 0;
    const char      *cstr = input.c_str();

    if (input.empty())
        return (UNDEFINED_E);
    if (input.size() == 1)
    {
        if (isprint(input.at(0)) && !isdigit(input.at(0)))
            return (CHAR_E);
    }
    if ((input.at(0)) != '-' && (input.at(0)) != '+' && !isdigit(input.at(0)))
        return (UNDEFINED_E);
    if (strchr(cstr, '.'))
    {
        if ((strchr(cstr, '.') == strrchr(cstr, '.')))
            decimal = 1;
        else
            return (UNDEFINED_E);
    }
    if (strchr(cstr, 'f'))
    {
        if ((strchr(cstr, 'f') == strrchr(cstr, 'f')))
            f = 1;
        else
            return (UNDEFINED_E); //inff??
    }
    for (size_t i = 0, j = input.size(); i < j; i++)
    {
        char curr = input.at(i);
        if (curr != '-' && curr != '+' && curr != '.' && curr != 'f' && !isdigit(curr))
        {
            return (UNDEFINED_E);
        }
    }
    if (decimal)
    {
        if (f)
            return (FLOAT_E);
        else
            return (DOUBLE_E);
    }
    else
        return (INT_E);
}

void ScalarConverter::convert(std::string input)
{
    int type;

    if (input.empty())
        return ;
    type = detectNativeType(input);
    if (type == UNDEFINED_E)
    {
        std::cout << "UNDEFINED type" << std:: endl;
        return ;
    }

    convertToChar(input, type);
    convertToInt(input, type);
    convertToFloat(input, type);
    convertToDouble(input, type);
}
