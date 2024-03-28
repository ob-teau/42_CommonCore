/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_filestream.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:43:44 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/11 11:50:49 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream	ifs("numbers"); //je passe en parametres numbers, un stream input
	unsigned int	dst;
	unsigned int	dst2;
	ifs >>dst >>dst2;

	std::cout <<dst <<" " <<dst2 <<std::endl;
	ifs.close();

	//-------------------

	std::ofstream	ofs("test.out");

	ofs <<"i like ponnies a whole damn lot" <<std::endl;
	ofs.close();


}
