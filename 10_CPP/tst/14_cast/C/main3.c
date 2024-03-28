/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:56:10 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/22 15:00:38 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void)
{
	int		a		= 42;						//Ref value

	int const	*b	= &a;						//Implicit type qualifier cast
	int const	*c	= (int const *) &a;			//Explicit type qualifier cast

	int const	*d	= &a;						//Implicit promotion	-> OK
	int *		e	= d;						//Implicit demotion		-> NO!!!
	int *		f	= (int *) d;				//Explicit demotion		-> OK
	return 0;
}
