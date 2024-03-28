/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_passages_deparametres_parref.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:14:26 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/11 09:42:01 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void byPtr(std::string* str)
{
	*str += " and ponies"; //ajoute une string a celle envoyee par pointer
}

void	byConstPtr(std::string const *str)
{
	std::cout <<*str <<std::endl; // affiche la string entiere
}

void	byRef(std::string& str)
{
	str += " and ponies"; //ajoute une string a celle envoyée par ref
}

void	byConstRef(std::string const &str)
{
	std::cout <<str <<std::endl; //affiche la string entiere
}

int main()
{
	std::string str = "i like butterflies";

	std::cout <<str <<std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "i like otters";

	std::cout <<str <<std::endl;
	byRef(str);
	byConstRef(str);

	return (0);
}
