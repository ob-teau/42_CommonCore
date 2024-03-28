/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:40:57 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/22 14:44:56 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void){

float a = 420.042f;			//reference value

void * b = &a;				//implicit reinterpretation cast
void * c = (void *) &a;		//explicit reinterpretation cast

void * d = &a;				//implicit promotion -> OK
int  * e = d;				//implicit demotion  -> Hsardeux !!
int  * f = (int *) d;		//explicit demotion  -> OK

}
