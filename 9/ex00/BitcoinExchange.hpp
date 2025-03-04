/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/03/04 18:14:43 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <limits>

#define DATABASE_FILE "data.csv"

class BitcoinExchange
{
    private:
        std::map<std::string, float> _database;

        void    	loadDatabase(std::string const &dbName);
		std::string	closestKey(std::string const &key);

        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &copy);
        BitcoinExchange &operator = (BitcoinExchange const &other);
        
    public:
        static BitcoinExchange&    getInstance();

        void    printData();
		void	customDataInput(std::string const &inputData);

        ~BitcoinExchange();
};
