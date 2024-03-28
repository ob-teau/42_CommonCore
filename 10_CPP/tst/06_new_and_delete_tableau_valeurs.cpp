/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_new_and_delete_tableau_valeurs.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:14:58 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/10 10:24:49 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student
{
	private:
		std::string _login;

	public:
		Student() : _login("ldefault"){
			std::cout <<"Student " <<this->_login <<" is born" <<std::endl;}

		~Student(){
			std::cout << "Student " <<this->_login <<" died" <<std::endl;}
};

int main()
{
	Student* students = new Student[42]; //pointeur sur student (students),on veut y alloer un tableau de 42 student, new array ne prend pas de parametres, trouver une autre technique pour initialiser les objets

//Do some suff here
	delete[] students; //desalloue les 42 student;
}
