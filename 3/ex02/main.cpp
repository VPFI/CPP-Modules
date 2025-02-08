/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:14 by vperez-f          #+#    #+#             */
/*   Updated: 2025/02/07 21:09:16 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void){
    
    FragTrap    frag1("Frag 1");
    ScavTrap    scav2("Scav 2");
    ScavTrap    scav3;

    for (int i = 0; i < 4; i++)
        frag1.attack("Bot 1");
    frag1.beRepaired(10);
    frag1.highFivesGuys();
    for (int i = 0; i < 3; i++)
        frag1.takeDamage(90);
    frag1.highFivesGuys();
    scav2.beRepaired(10);
    scav2.takeDamage(15);
    scav2.takeDamage(15);
    scav2.beRepaired(10);
    return (0);
}