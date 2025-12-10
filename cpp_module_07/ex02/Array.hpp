/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:50:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/09 17:50:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


template <typename T>
class Array {

public:
	Array();
	Array( unsigned int n );
	Array( const Array<T>& other );
	~Array();

	Array<T>&	operator = ( const Array<T>& other );
	T&		operator [] ( unsigned int i );
	const T&	operator [] ( unsigned int i ) const;
	
	T*		getArray() const;
	unsigned int	size() const;

private:
	T* 		_array;
	unsigned int	_size;
};

#include "Array.tpp"

#endif

