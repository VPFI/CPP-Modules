/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/04/14 19:38:45 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <list>

int main()
{
	{
		MutantStack<int> mstack;
		const MutantStack<int> cstmstack;
		//const MutantStack<int>::const_iterator itea = cstmstack.begin();

		//cstmstack.push(5);
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		//MutantStack<int>::const_iterator cstit = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::list<int> list_test;
		list_test.push_back(5);
		list_test.push_back(17);
		std::cout << list_test.back() << std::endl;
		list_test.pop_back();
		std::cout << list_test.size() << std::endl;
		list_test.push_back(3);
		list_test.push_back(5);
		list_test.push_back(737);
		//[...]
		list_test.push_back(0);
		std::list<int>::iterator it = list_test.begin();
		std::list<int>::iterator ite = list_test.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(list_test);
	}

	return 0;
}
