/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_references.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:51:04 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/11 09:13:11 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	int		numberOfBalls = 42; //un int

	int*	ballsPtr = &numberOfBalls; //un pointeur initialisé sur l'adresse de  l'int numberOfBalls
	int&	ballsRef = numberOfBalls; //type reference sur int, y affecter la variable nbOfBalls et pas son adresse, la reference pointe sur cette variabe, je ne peux plus changer ce sur quoi ma ref pointe 
//int& ballsRef; == FAUX, une ref est TOUJOURS initiaisée

	std::cout << numberOfBalls << " " <<*ballsPtr <<" " <<ballsRef <<std::endl;
//affiche la variable numberOfBalls <<ballspointer qui pointe sur nbOfBalls déréférencé pour acceder a ce sur quoi le pointeur pointe 
//<<ref vers nbOfBalls
	*ballsPtr = 21; //déréférencer pointeur pour acceder a numberOfBalls et y affecter 21;
	std::cout << numberOfBalls <<std::endl;
	ballsRef = 84;
	std::cout << numberOfBalls <<std::endl;

	return (0);
}
