/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:30:14 by vpf               #+#    #+#             */
/*   Updated: 2025/02/14 01:42:49 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat  b1("11111", 10);
    Bureaucrat  b2("22222", 75);
    Form        f1("f1", 8, 8);

    std::cout << std::endl;
    b2.signForm(f1);
    std::cout << f1 << std::endl;
    b1.signForm(f1);
    std::cout << f1 << std::endl;
    b1.incrementGrade();
    b1.incrementGrade();
    b1.signForm(f1);
    std::cout << b1 << std::endl;
    std::cout << f1 << std::endl;
    b1.decrementGrade();
    b1.signForm(f1);
    std::cout << f1 << std::endl;
}