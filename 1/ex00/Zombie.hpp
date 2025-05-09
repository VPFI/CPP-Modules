/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:18:50 by vpf               #+#    #+#             */
/*   Updated: 2025/01/31 17:50:08 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string	_name;

		void	_set_name(std::string name);
		
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce( void );
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
