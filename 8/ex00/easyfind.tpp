/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:34 by vpf               #+#    #+#             */
/*   Updated: 2025/02/26 21:38:58 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "easyfind.hpp"

template <typename T>
void	easyfind(T &a, int b)
{
    typename T::iterator index = std::find(a.begin(), a.end(), b);
    
    if (index != a.end())
        std::cout << "Element found at index: " << std::distance(a.begin(), index) << std::endl;
    else
        throw(std::runtime_error("Element not found"));
}
