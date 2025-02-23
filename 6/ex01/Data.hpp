/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:12:09 by vpf               #+#    #+#             */
/*   Updated: 2025/02/24 00:31:28 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Data
{
    protected:
        int _testData;

    public:
        Data();
        Data(int num);
        Data(const Data &copy);
        ~Data();

        Data &operator = (const Data &c);

        int getData(void) const;
};