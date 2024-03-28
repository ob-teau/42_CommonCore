/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:14:04 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/15 11:32:42 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"

int	main(){
	Sample	instance1; //creation d'instance avec constructeur par defaut
	Sample	instance2(42); //creation d'instance avec constructeur par parametre (attribut initialisé par parametre)
	Sample	instance3(instance1); //creation d'instance avec constructeur par copie (Prend une instance de la meme classe en parametres)

	std::cout <<instance1 <<std::endl;
	std::cout <<instance2 <<std::endl;
	std::cout <<instance3 <<std::endl;

	instance3 = instance2; //appel a la surcharge d'e l'operateur d'assignation (mise a jour de l'instance3 avec le contenue d'istance2)
	std::cout <<instance3 <<std::endl;
	return (0);
}
