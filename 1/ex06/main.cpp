/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:28:27 by vpf               #+#    #+#             */
/*   Updated: 2025/02/02 01:34:40 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;

    if (argc != 2)
    {
        std::cout
            << "./harlFilter [COMPLAINT] || "
            << "Formal complaints being: "
            << "DEBUG | INFO | WARNING | ERROR"
        << std::endl;

        return (1);
    }
    else
    {
        harl.complain(argv[1]);

        return (0);
    }
}