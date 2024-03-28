/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:46:08 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/13 14:17:58 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void){std::cout <<"constructeur" <<std::endl;}

Sample::~Sample(void){std::cout <<"destructeur" <<std::endl;}

void Sample::bar(char const c) const {
    std::cout <<"member ft called with char overload : " <<c <<std::endl;
	return;
}

void Sample::bar(int const n) const {
    std::cout <<"member ft called with int overload : "  <<n <<std::endl;
	return;
}


void Sample::bar(float const z) const {
	std::cout <<"member ft called with float overload : " <<z <<std::endl;
	return;
 }

void Sample::bar(Sample const & i) const{
	(void) i;

	std::cout <<"member ft called with Sample overload" <<std::endl;
	return;
}
