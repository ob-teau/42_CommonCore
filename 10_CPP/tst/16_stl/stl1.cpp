/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:40:45 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/24 15:11:51 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include <list>

class IOperator;

int main()
{
	std::list<int>							lst1;		//list templatée sur int (une list qui va contenir de ints)
	std::map<std::string, IOperation*>		map1;		//map de ioperation indexe sur des strings
	std::vector<int>						v1;				//initialisation de vector
	std::vector<int>						v2(42, 100);	//init de vector, creer 42 entrees qui vont par defaut contenir 100

	lst1.push_back(1);									//operation qui permet d'operer sur une list
	lst1.push_back(17);
	lst1.push_back(42);

	map1["opA"] = new OperationA;
	map1["opB"] = new OperationB;

	std::list<int>::const_iterator		it;					//instencier un const iterator sur liste d'int 
	std::list<int>::const_iterator		ite = lst1.end();	//list1.end une valeur qui signifie qu'on a depassé le dernier element
	for (it = lst1.begin(); it != ite; ++it){
		std::cout <<*it <<std::endl;}
	return 0;
}
