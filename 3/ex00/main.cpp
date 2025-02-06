/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:14 by vperez-f          #+#    #+#             */
/*   Updated: 2025/02/06 18:34:16 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void){

    ClapTrap    AAAA("AAAA");
    ClapTrap    BBBB("BBBB");

    for (int i = 0; i < 12; i++)
        AAAA.attack("Bot 1");
    AAAA.beRepaired(1000);
    for (int i = 0; i < 3; i++)
        AAAA.takeDamage(6);
    BBBB.beRepaired(10);
    BBBB.takeDamage(15);
    BBBB.takeDamage(15);
    BBBB.beRepaired(10);
    return (0);

}