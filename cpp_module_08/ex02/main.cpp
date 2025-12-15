/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:56:11 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/15 13:56:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main() {

	std::cout << "Creating the objects of stack using default/copy constructors and assignment operator... " << std::endl;
	MutantStack<std::string>	myStack;
	MutantStack<std::string>	myStack1(myStack);
	MutantStack<std::string>	myStack2;
	myStack2 = myStack;
	std::cout << "done" << std::endl << std::endl;
	

	std::cout << "Pushing some strings inside ..." << std::endl;
	myStack.push("hello");
	myStack.push("hello1");
	myStack.push("hello2");
	myStack.push("hello3");
	myStack.push("hello4");
	std::cout << "done" << std::endl << std::endl;


	std::cout << "Removing the last string and printing the latest string: " << std::endl;
	myStack.pop();
	std::cout << myStack.top() << std::endl << std::endl;


	std::cout << "Using an iterator to see all strings inside the class: " << std::endl;
	MutantStack<std::string>::iterator iter = myStack.begin();
	while (iter < myStack.end()){
		std::cout << *iter << std::endl;
		iter++;
	}
	std::cout << std::endl;

	std::cout << "--------------------------------------------------------------------" << std::endl << "Test from the subject: " << std::endl;
	
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Stack has 5 and 17. The top one is : " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "Deleted 1 element from stack. Stack's size is: " << mstack.size() << std::endl;
	
	std::cout << "Pushing 3 - 5 - 737 - 0" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	return 0;
}

