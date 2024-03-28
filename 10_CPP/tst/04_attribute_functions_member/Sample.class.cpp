/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:53:53 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/06 14:41:08 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) {  //Constructor
	std::cout << "Constructor called" << std::endl;
	this->foo = 42; //mettre la variable foo de mon instance courante a la valeur 42
	std::cout << "this->foo: " << this->foo << std::endl;

	this->bar();

	return;
}

Sample::~Sample(void) { // Destructor
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::bar(void) { // Member function
	std::cout << "Member function bar called" << std::endl;
	return;
}
