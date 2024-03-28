/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:54:14 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/15 11:44:44 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"

Sample::Sample(void) : _foo(0) {
	std::cout <<"default constructor called" <<std::endl;}

Sample::Sample(int const n) : _foo(n) {
	std::cout <<"parametric onstructor called" <<std::endl;}

Sample::Sample(Sample const & src) {
	std::cout <<"Copy constructor called" <<std::endl;
	*this=src;}

Sample::~Sample(){
	std::cout <<"destructor called" <<std::endl;}

Sample & Sample::operator=(Sample const & rhs){
	std::cout <<"assignement operator called" <<std::endl;
	if (this != &rhs)
		this->_foo = rhs.getFoo();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Sample const & i) {
	o << "the value of _foo is :" <<i.getFoo();
	return o;
}

int		Sample::getFoo() const{
	return (this->_foo);
}
