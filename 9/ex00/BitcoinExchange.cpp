/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:34 by vpf               #+#    #+#             */
/*   Updated: 2025/03/04 19:46:14 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    loadDatabase(DATABASE_FILE);

    return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
    (void)copy;

    return ;
}

BitcoinExchange &BitcoinExchange::operator = (BitcoinExchange const &other)
{
    (void)other;

    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    return ;
}

void    BitcoinExchange::loadDatabase(std::string const &dbName)
{
    std::fstream                csv;
    std::string                 line;
    std::string                 key;
    float                       value;

    csv.open(dbName.c_str());
    if (csv.is_open())
    {
        while (getline(csv, line))
        {
            key = line.substr(0, line.find(','));
			if (!isdigit(key.at(0)))
				continue ;
            value = std::atof((line.substr(line.find(',') + 1)).c_str());
            this->_database[key] = value;
        }
    }
    else
        throw (std::runtime_error("Couldn't open database"));
    csv.close();
}

BitcoinExchange &BitcoinExchange::getInstance()
{
    static BitcoinExchange instance;

    return (instance);
}

static bool checkValue(long value)
{
	if (value > 1000)
		std::cerr << "Error: too large a number" << std::endl;
	else if (value < 0)
		std::cerr << "Error: not a positive number" << std::endl;
	else
		return (1);
	return (0);
}

static bool checkDateKey(std::string const &key)
{
	long	year = std::atol(key.substr(0, key.find('-')).c_str());
	long	month = std::atol(key.substr(key.find('-') + 1, key.rfind('-')).c_str());
	long	day = std::atol(key.substr(key.rfind('-') + 1).c_str());

	if (year < 0 || year > std::numeric_limits<int>::max()
		|| month <= 0 || month > 12
		|| day <= 0 || day > 31)
	{
		std::cerr << "Error: bad input => " << key << std::endl;

		return (0);
	}

	return (1);
}

static bool	checkFormat(std::string const &key, long value)
{
	if (!checkDateKey(key) || !checkValue(value))
	{
		return (0);
	}

	return (1);
}

std::string	BitcoinExchange::closestKey(std::string const &key)
{
	try
	{
		if (this->_database.at(key))
			return (key);
	}
	catch(const std::exception& e) {}
	std::string	resKey = "NULL";
	std::map<std::string, float>::iterator it = this->_database.begin();
	while (it != this->_database.end())
	{
		if (it->first > key)
			break ;
		resKey = it->first;
		it++;
	}
	return (resKey);
}

void	BitcoinExchange::customDataInput(std::string const &inputData)
{
	std::fstream                inputFile;
    std::string                 line;
    std::string                 inputKey;
    float                       valueModifier;

    inputFile.open(inputData.c_str());
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            inputKey = line.substr(0, line.find('|') - 1);
            valueModifier = std::atof((line.substr(line.find('|') + 1)).c_str());
			if (!checkFormat(inputKey, valueModifier))
				continue ;
			std::cout << inputKey;
			inputKey = closestKey(inputKey);
            std::cout << " => " << valueModifier << " = " << (this->_database.at(inputKey) * valueModifier) << std::endl;
        }
    }
    else
        throw (std::runtime_error("Couldn't open input data"));
    inputFile.close();

	return ;
}

void	BitcoinExchange::printData()
{
    for (std::map<std::string, float>::iterator it = this->_database.begin(); it != this->_database.end(); it++)
	{
        std::cout << "Key: " << it->first << " || Value: " << it->second << std::endl;
    }
}
