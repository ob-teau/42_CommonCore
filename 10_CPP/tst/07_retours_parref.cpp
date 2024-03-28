/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_retours_parref.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:57:55 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/11 11:43:22 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student
{
	private:
		std::string _login;


	public:
		Student(std::string const & login) : _login(login)
		{
		}

		std::string&	getLoginRef()
		{
			return	this->_login; //renvoie une rf sur login (je retourne la variable membre sans me soucier de prendre son adresse)
		}

		std::string const & getLoginRefConst() const
		{
			return this->_login; // renvoie une ref const sur login
		}

		std::string* getLoginPtr()
		{
			return &(this->_login); // renvoie une pointeur sur login (je prend l'adresse)
		}

		std::string const * getLoginPtrConst() const
		{
			return &(this->_login); //renvoie un pointeur const sur login
		}

};

int main()
{
	Student			bob = Student("bfubar");
	Student const	jim = Student("jfubar"); //const qui ne modifie pas l'objet

	std::cout <<bob.getLoginRefConst() <<" " <<jim.getLoginRefConst() << std::endl; // possibiliter d'utiliser une fonction const
	std::cout <<*(bob.getLoginPtrConst()) <<" " <<*(jim.getLoginPtrConst()) <<std::endl; //[sur une variable non const.
//login de jim const donc pas modifiable
	bob.getLoginRef()= "bobfubar"; //affecter bobfubar au retour de getLoginRef
	std::cout <<bob.getLoginRefConst() <<std::endl;

	*(bob.getLoginPtr()) = "bobbyfubar";
	std::cout <<bob.getLoginRefConst() <<std::endl;
}
