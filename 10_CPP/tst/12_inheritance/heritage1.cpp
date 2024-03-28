/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage1.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 08:41:23 by alice             #+#    #+#             */
/*   Updated: 2022/06/16 08:50:00 by alice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class cat {

private:
		int _numberOfLegs;

public:
		Cat();
		Cat(Cat const &);
		Cat& operator=(Cat const &);
		~Cat();

		void	run(int distance);

		void	scornSomeone(std::string const & target);
};

class Pony {

	private:
			int	_numberOfLegs;

	public:
			Pony();
			Pony(Pony const &);
			Pony& operator=(POny const &);
			~POny();

			void run(int distance);

			void doMagic(std::string const & target);
};
