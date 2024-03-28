/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions1.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:30:23 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/21 12:01:34 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

void test1()
{
	try //block try : je vais essayer de faire qc qui pourra renvoyer une exception
	{
		//do some stuff here
		if (/*there's an error*/){
			throw std::exception();} //si je rentre dans la condition je throw (lance) une exception
		else {
			//do some more stuff}
	}
	catch (std::exception e){ // je veux catcher une std::xception que je vais appeler e
		/*gerer mon erreur ici*/}
}
//si dans mon try jai alloué des resources, dans mon catch je vais les desallouer

