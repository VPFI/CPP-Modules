/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:11:34 by vpf               #+#    #+#             */
/*   Updated: 2025/02/01 23:30:31 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace_file.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Invalid number of parameters | Filename [ocurrence] [replacement]" << std::endl;
        return (1);
    }
    replace_file(argv[1], argv[2], argv[3]);
}
