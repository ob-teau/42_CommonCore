/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:20:08 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/23 13:28:16 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


template <typename T>
	T	const & max(T const & x, T & y){	//T designe un type quelconque mais systematiquement le meme
									//par reference pour si on a une class volumineuse
									//const car fonction max ne modifie pas instance x ou y
	return (x >= y ? x : y);}
/* definir un template de fonction (utiliser le mot template)
 * apres le templateate, entre chevron : la liste

