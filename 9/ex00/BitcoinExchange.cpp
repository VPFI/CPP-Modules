/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:34 by vpf               #+#    #+#             */
/*   Updated: 2025/03/04 01:04:37 by vpf              ###   ########.fr       */
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

void    BitcoinExchange::loadDatabase(std::string dbName)
{
    std::fstream                csv;
    std::string                 line;
    std::string                 key;
    int                         value;

    csv.open(dbName.c_str());
    if (csv.is_open())
    {
        while (getline(csv, line))
        {
            key = line.substr(0, line.find(','));
            value = std::atoi((line.substr(line.find(',') + 1)).c_str());
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

void BitcoinExchange::test() {
    for (std::map<std::string, int>::iterator it = _database.begin(); it != _database.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}
