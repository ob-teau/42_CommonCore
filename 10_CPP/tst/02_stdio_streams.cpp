/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_stdio_streams.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:23:20 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/06 14:45:30 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void){

	char buff[512];

	std::cout << "Hello world !" <<std::endl; //rediriger hellow world dans la sortie standard suivi d'un retour a la ligne;

	std::cout << "Input a world: ";
	std::cin >> buff;
	std::cout << "you entered [" <<buff <<"]" <<std::endl;

	return 0;
}
