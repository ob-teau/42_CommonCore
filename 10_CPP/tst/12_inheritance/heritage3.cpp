/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage3.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:11:50 by alice             #+#    #+#             */
/*   Updated: 2022/06/18 14:02:45 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Quadruped //  a acces a name, run() et Legs
{
public:
			void	run(); // accessibe depuis partout
protected:
			Leg		Legs[4]; //accessible depuis le quadruped et le dog (puisque c'est une classe derivee depuisle quadruped)
private:
			std::string name; //accessible depuis le quadruped SAULEMENT (pas accessible depuis dog par ex), appartient seulemet a la classe mere
};

class Dog : public Quadruped //posssibilité de mettre protected et private (niveau d'encapsulation d'heritage )
{
};

int main()
{
}
///heritage en diamant
//
