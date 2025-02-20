/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:17 by vpf               #+#    #+#             */
/*   Updated: 2025/02/20 19:22:26 by vperez-f         ###   ########.fr       */
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
	(void)type;
	int rawValue = std::atoi(input.c_str());

	if (type == CHAR_E)
	{
		std::cout << "char: '" << input << "'" << std::endl;
	}
	else if (std::isprint(rawValue))
	{
		std::cout << "char: '" << static_cast<unsigned char>(rawValue) << "'" << std::endl;
	}
	else
	{
		std::cout << "char: " << "Non displayable" << std::endl;
	}
}

static void    convertToInt(std::string &input, int type)
{
    if (type == INT_E)
    {
        std::cout << "int: " << input << std::endl;       
    }
	else if (type == CHAR_E)
	{
		std::cout << "int: " << static_cast<int>(input.at(0)) << std::endl;
	}
    else
	{
        std::cout << "int: " << std::atoi(input.c_str()) << std::endl;
	}
}

static void    convertToFloat(std::string &input, int type)
{
	std::cout.precision(1);
	std::cout.setf(std::ios::fixed);
	if (type == FLOAT_E || type == DOUBLE_E)
	{
		if (type == FLOAT_E)
			std::cout << "float: " << input << std::endl;
		else
			std::cout << "float: " << input << "f" << std::endl;
	}
	else if (type == CHAR_E)
	{
		std::cout << "float: " << static_cast<float>(input.at(0)) << "f" << std::endl;
	}
    else
	{
        std::cout << "float: " << static_cast<float>(std::atof(input.c_str())) << "f" << std::endl;
	}
	std::cout.unsetf(std::ios::fixed);
}

static void    convertToDouble(std::string &input, int type)
{
	std::cout.precision(1);
	std::cout.setf(std::ios::fixed);
	if (type == DOUBLE_E || type == FLOAT_E)
	{
		if (type == DOUBLE_E)
			std::cout << "double: " << input << std::endl;
		else
		{
			input.erase(input.size() - 1);
			std::cout << "double: " << input << std::endl;
		}
	}
	else if (type == CHAR_E)
	{
		std::cout << "double: " << static_cast<double>(input.at(0)) << std::endl;
	}
    else
	{
        std::cout << "double: " << static_cast<double>(std::atof(input.c_str())) << std::endl;
	}
	std::cout.unsetf(std::ios::fixed);
}

static int	checkSingleOccurrence(const char *cstr, const char target, int &flag)
{
	if (strchr(cstr, target))
    {
        if ((strchr(cstr, target) == strrchr(cstr, target)))
		{
			flag = 1;
			return (1);
		}
		return (-1);
	}
	return (0);
}

static int	checkInvalidChars(std::string &input)
{
	if (!isdigit(input.at(0)) && (input.at(0)) != '-' && (input.at(0)) != '+')
		return (-1);
	for (size_t i = 1, j = input.size(); i < j; i++)
	{
		char curr = input.at(i);
		if (!isdigit(curr) && curr != '.')
		{
			if (curr == 'f' && i == (j - 1))
				continue ;
			return (-1);
		}
	}
	return (0);
}

static int	checkNanInf(std::string &input)
{
	if (input == "+inf" || input == "-inf" || input == "nan")
		return (DOUBLE_E);
	if (input == "+inff" || input == "-inff" || input == "nanf")
		return (FLOAT_E);
	return (0);
}

static int	detectNativeType(std::string &input)
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
	if (checkNanInf(input))
	if (checkInvalidChars(input) < 0)
		return (UNDEFINED_E);
    if (checkSingleOccurrence(cstr, '.', decimal) < 0)
		return (UNDEFINED_E);
    if (checkSingleOccurrence(cstr, 'f', f) < 0)
		return (UNDEFINED_E);
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
