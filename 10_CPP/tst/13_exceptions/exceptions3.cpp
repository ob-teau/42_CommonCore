/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions3.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:59:50 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/21 12:01:11 by acoinus          ###   ########.fr       */
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

void	test4()
{


	class PEBKACException :public std::exceptions //definir une nouvelle exception en heritant de std::exception PEBKACException est donc une std::exception et herite de son comportement
	{
		public:
				virtual const char *what() const throw() //throw specifieur (a la fin d'une definition de fonction) cette fonction peut throw qc ou pas (ici pas)
				{
					return("Problem exists");
				}
	};


	try {
		test3();}
	catch (PEBKACException & e)
	{
		//si test3 renvoie une PEBKACException je la gere ici -> catch specifique
	}
	catch (std::exception e)
	{
		//si test3 renvoie toute autre exception qui herite de ces exception ou qui est une exception je la gere ici ->catch generique
	}

}

