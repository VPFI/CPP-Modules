/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/03/04 01:05:12 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

#define DATABASE_FILE "btcData.csv"

class BitcoinExchange
{
    private:
        std::map<std::string, int> _database;

        void    loadDatabase(std::string dbName);

        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &copy);
        BitcoinExchange &operator = (BitcoinExchange const &other);
        
    public:
        static BitcoinExchange&    getInstance();

        ~BitcoinExchange();

        void    test();
};
