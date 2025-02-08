/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:14 by vperez-f          #+#    #+#             */
/*   Updated: 2025/02/08 00:53:30 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
    DiamondTrap	Diamond1;
	DiamondTrap	Diamond2("TEST");
    DiamondTrap	Diamond3(Diamond2);

	Diamond2.guardGate();
	//Diamond2.highFivesGuys();


    for (int i = 0; i < 101; i++)
        Diamond2.attack("111111");
    Diamond2.beRepaired(20);


    Diamond3.attack("111111");
    Diamond3.takeDamage(10000);
    Diamond3.beRepaired(20);
    Diamond2.beRepaired(20);

    Diamond2.whoAmI();
    Diamond3.whoAmI();
}