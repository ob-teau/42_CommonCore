/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 08:55:45 by alice             #+#    #+#             */
/*   Updated: 2022/06/18 11:59:45 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Animal {
private:
		int _numberOfLegs;

public:
		Animal();
		Animal(Animal const &);
		Animal& operator=(Animal const &);
		~Animal();

		void run(int distance);
};

class Cat : public Animal { //Le chat herite de l'animal, il a le comportement de l'animal
public:
		Cat();
		Cat(Cat const &);
		Cat& operator=(Cat const &);
		~Cat();

		void	scornSomeone(std::string const & target); // il a aussi son propre comportement
};

class Pony : public Animal{
public:
		Pony();
		Pony(POny const &);
		Pony& operator=(Pony const &);
		~Pony();

		void	doMagic(std::string const &target);
		void	run(int distance); //va venir remplacer la fonction run de animal
}

//comment appeler le constructeur de son parent
//s'assurer que le destructeur est bien appelé pour les 2
/
