/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:18:48 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/21 16:18:48 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	printFloat(float nb) {

	std::cout << nb << std::endl;
}

int	main()
{
	printFloat(1);
	printFloat(-1.);
	//printFloat(1f); //wrong
	printFloat(1.f);

}
