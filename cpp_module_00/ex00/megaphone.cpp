/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:26:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/09 13:55:43 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char** av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for(int	j = 1; av[j]; j++)
		{
			for (int i = 0; av[j][i]; i++)
			{
				if (av[j][i] >= 'a' && av[j][i] <= 'z')
					av[j][i] -= 32;
				std::cout << av[j][i];
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
