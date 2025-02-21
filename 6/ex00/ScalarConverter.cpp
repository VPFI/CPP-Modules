/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:17 by vpf               #+#    #+#             */
/*   Updated: 2025/02/21 18:35:37 by vpf              ###   ########.fr       */
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

static bool	isEdgeCase(std::string &input)
{
	if (input == "+inf" || input == "+inff" || input == "-inf"
		|| input == "-inff" || input == "nan" || input == "nanf")
	{
		return (true);
	}
	return (false);
}

static void    convertToChar(std::string &input, e_inputType type)
{
	(void)type;
	int rawValue = std::atoi(input.c_str());

	std::cout << "char: ";
	if (type == CHAR_E)
	{
		std::cout << "'" << input << "'";
	}
	else if (std::isprint(rawValue))
	{
		std::cout << "'" << static_cast<unsigned char>(rawValue) << "'";
	}
	else if (isEdgeCase(input))
	{
		std::cout << "impossible";
	}
	else
	{
		std::cout << "Non displayable";
	}
	std::cout << std::endl;
}

static bool	checkLimits(std::string &input)
{
	if (input.size() > 11)
	{
		std::cout << "impossible" << std::endl;
		return (true);
	}
	else
	{
		long long num = std::atoll(input.c_str());
		if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		{
			std::cout << "impossible" << std::endl;
			return (true);
		}
	}
	return (false);
}

static void	convertToInt(std::string &input, e_inputType type)
{
	std::cout << "int: ";
	if (checkLimits(input))
		return ;
	else if (isEdgeCase(input))
	{
		std::cout << "impossible";
	}
	else if (type == CHAR_E)
	{
		std::cout << static_cast<int>(input.at(0));
	}
    else
	{
        std::cout << std::atoi(input.c_str());
	}
	std::cout << std::endl;
}

static void    convertToFloat(std::string &input, e_inputType type)
{
	std::cout.precision(1);
	std::cout.setf(std::ios::fixed);
	std::cout << "float: ";
	if (type == CHAR_E)
	{
		std::cout << static_cast<float>(input.at(0)) << "f";
	}
    else
	{
        std::cout << static_cast<float>(std::atof(input.c_str())) << "f";
	}
	std::cout << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

static void    convertToDouble(std::string &input, e_inputType type)
{
	std::cout.precision(1);
	std::cout.setf(std::ios::fixed);
	std::cout << "double: ";
	if (type == CHAR_E)
	{
		std::cout << static_cast<double>(input.at(0));
	}
    else
	{
        std::cout << static_cast<double>(std::atof(input.c_str()));
	}
	std::cout << std::endl;
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

static e_inputType	checkNanInf(std::string &input)
{
	if (input == "+inf" || input == "-inf" || input == "nan")
		return (DOUBLE_E);
	if (input == "+inff" || input == "-inff" || input == "nanf")
		return (FLOAT_E);
	return (STD_E);
}

static bool	checkForChar(std::string &input)
{
	if (input.size() == 1)
    {
        if (isprint(input.at(0)) && !isdigit(input.at(0)))
            return (true);
    }
	return (false);
}

static void	checkFormat(std::string &input, int &f, int &decimal)
{
	const char      *cstr = input.c_str();

	if (checkInvalidChars(input) < 0)
		throw (std::runtime_error("UNDEFINED type"));
	if (checkSingleOccurrence(cstr, '.', decimal) < 0)
		throw (std::runtime_error("UNDEFINED type"));
	if (checkSingleOccurrence(cstr, 'f', f) < 0)
		throw (std::runtime_error("UNDEFINED type"));
}

static e_inputType	detectNativeType(std::string &input)
{
    int             f       = 0;
    int             decimal = 0;

    if (input.empty())
		throw (std::runtime_error("UNDEFINED type"));
	if (checkForChar(input))
		return (CHAR_E);
	if (checkNanInf(input))
		return (checkNanInf(input));
	checkFormat(input, f, decimal);
    if (decimal)
    {
        if (f)
            return (FLOAT_E);
        else
            return (DOUBLE_E);
    }
	return (INT_E);
}

void ScalarConverter::convert(std::string input)
{
    e_inputType type;

    if (input.empty())
		return ;
	try
    {
		type = detectNativeType(input);

		convertToChar(input, type);
		convertToInt(input, type);
		convertToFloat(input, type);
		convertToDouble(input, type);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
