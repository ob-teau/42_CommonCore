/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions2.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:46:40 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/21 12:00:45 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

void	test2()
{
	//do some stuff here
	if (/*erreur*/){
		throw std::exception();}
	else {
		//do some stuff here}
}

void test3()
{
	try {
		test2();}
	catch (std::exception & e){ //possibilité de catcher une exception par ref
		/*gerer erreur ici*/}
}

