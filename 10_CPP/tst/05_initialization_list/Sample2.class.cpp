/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample2.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:56:42 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/06 15:24:15 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample2.class.hpp"

Sample2::Sample2(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) //permet d'initialiser les attributs
{
	std::cout << "Constructor called" << std::endl;

	std::cout << "this->a1 = " <<this->a1 <<std::endl;
	std::cout << "this->a2 = " <<this->a2 <<std::endl;
	std::cout << "this->a3 = " <<this->a3 << std::endl;
}

Sample2::~Sample2(void)
{
	std::cout <<"Destructor called" <<std::endl;
	return;
}

