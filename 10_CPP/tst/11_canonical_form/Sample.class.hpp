/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:28:12 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/15 12:03:23 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

# include <iostream>

class Sample {

public:
		Sample(void);						//CANONICAL, constructeur par defaut
		Sample(int  const n);				//constructeur par parametre
		Sample(Sample const & src);		//CANONICAL, constructeur par copie
		~Sample(void);						//CANONICAL, destructeur

		Sample &	operator=(Sample const & rhs);	//CANONICAL, operateur d'assignation égal

		int			getFoo(void) const;				//Accesseur pour membre foo

private:
		int _foo;

//possibilite d'ajouter une fonction membre permettant de lire la classe en string pour le debugage
};

std::ostream &		operator <<(std::ostream & o, Sample const & i); //surcharge de chevrons gauche pour la redirection de flux sur la sortie standard

#endif
