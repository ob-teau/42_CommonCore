/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_polymorphism.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:45:46 by acoinus           #+#    #+#             */
/*   Updated: 2022/06/13 13:50:03 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{
    public:
        Sample(void);
        ~Sample(void);
    //4 surcharges d'une fonction membre bar
        void bar(char const c) const;
        void bar(int const n) const;
        void bar(float const z) const;
        void bar(Sample const & i) const; //reference de sample constante
};

#endif
