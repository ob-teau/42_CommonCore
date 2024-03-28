/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_new_and_delete.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:55:54 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/10 10:13:05 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student {

	private :
		std::string _login;

	public :
		Student(std::string login) : _login(login)
		{
			std::cout << "student " <<this->_login <<" is born" <<std::endl;
		}

		~Student()
		{
			std::cout  <<"student "  <<this->_login  <<" died"  <<std::endl;
		}};

int	main()
{
	Student	bob  = Student("bfubar"); //alloue statiquement sur la pile, sera desallouee automatiquement qund je sors de ma fonction, quand la stack va etre delete
	Student*	jim = new Student("jfubar"); //allouer (new) un student de maniere dynamique (pointeur sur student) : malloc + appel de constructeur de Student (pour l'initialiser correctement) + renvoyer un pointeur sur l'instance obtenue

	//Do some stuff here

	delete jim; //jim is destroyed
	return(0); //bob is destroyed
}
