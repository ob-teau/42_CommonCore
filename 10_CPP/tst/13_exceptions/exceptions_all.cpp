/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions_all.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:00:08 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/21 12:00:21 by acoinus          ###   ########.fr       */
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

-------------------------------------------------------------------------------------------

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


