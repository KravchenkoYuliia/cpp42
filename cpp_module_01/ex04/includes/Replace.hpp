/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:37:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/30 13:49:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>


class Replace { 

public:
	Replace(std::string fileName, std::string oldText, std::string newText);
	~Replace();

	void	Process();

private:
	std::string	fileName;
	std::string	oldText;
	std::string	newText;


};
