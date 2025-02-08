/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:14 by vperez-f          #+#    #+#             */
/*   Updated: 2025/02/07 20:36:09 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void){
    
    ScavTrap    scav1("Scav 1");
    ScavTrap    scav2("Scav 2");
    ScavTrap    scav3;

    for (int i = 0; i < 4; i++)
        scav1.attack("Random enemy 1");
    scav1.beRepaired(10);
    for (int i = 0; i < 3; i++)
        scav1.takeDamage(90);
    scav2.beRepaired(10);
    scav2.takeDamage(15);
    scav2.takeDamage(15);
    scav2.beRepaired(10);

    scav2.guardGate();

    //scav3 = scav1;
    scav3.attack( "Random enemy 2");

    scav3.guardGate();
    
    ClapTrap    Clappy;
    Clappy.attack("Clappy2");
    Clappy.takeDamage(10);
    Clappy.beRepaired(100);
    return (0);

}