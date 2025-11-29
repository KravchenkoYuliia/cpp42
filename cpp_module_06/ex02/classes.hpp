/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:05:12 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/29 16:05:12 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Base { public: virtual ~Base() {}; };

class A: public virtual Base {};
class B: public virtual Base {};
class C: public virtual Base {};
