/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:09:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/27 02:27:11 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
    private:
        
    public:
        MutantStack();
        ~MutantStack();
};

#include "MutantStack.tpp"