/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:11:57 by vpf               #+#    #+#             */
/*   Updated: 2025/02/24 00:36:08 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _testData(0)
{
    std::cout
        << "Default Data constructor called"
    << std::endl;

    return ;
}

Data::Data(int num) : _testData(num)
{
    std::cout
        << "Value Data constructor called"
    << std::endl;

    return ;
}

Data::Data(const Data &copy)
{
    std::cout
        << "Copy Data constructor called"
    << std::endl;
    *this = copy;

    return ;
}

Data::~Data()
{
    std::cout
        << "Data destructor called"
    << std::endl;    
}

Data &Data::operator = (const Data &other)
{
    if (this != &other)
    {
        this->_testData = other._testData;
    }
    return (*this);
}

int Data::getData() const
{
    return (this->_testData);
}
