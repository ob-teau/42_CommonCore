/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:47:03 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/14 15:56:21 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.class.hpp"

Integer::Integer(int const n) :_n(n){
}

Integer::~Integer(void){}

int	Integer::getvalue() const{
	return (this->_n);
}

Integer & Integer::operator=(Integer const & rhs){
	this->_n = rhs.getvalue();
	return (*this);
}
