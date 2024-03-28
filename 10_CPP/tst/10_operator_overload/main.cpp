/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:26:41 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/14 16:24:43 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Integer.class.hpp"

int main(){
	Integer		x(30);
	Integer		y(10);
	Integer		z(0);

	x = y;
	x. = (y); // x -> instance, = ->fonction, y -> parametre
	std::cout <<"value of x :" <<x <<std::endl;
	std::cout <<"value of y :" <<y <<std::endl;
	y = Integer(12);
	std::cout <<"value of y :" <<y <<std::endl;
	std::cout <<"value of z :" <<z <<std::endl;
	z = x+y;
	std::cout <<"value of z :" <<z <<std::endl;
	return 0;
}
