/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:16:53 by acoinus           #+#    #+#             */
/*   Updated: 2021/09/02 16:57:43 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>

# define TYPE "%cspdiuxX"

typedef struct s_info
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	char	type;
	int		i;
	int		res;
	int		sign;
	int		nbr_base;
	int		is_width;
	int		is_prec;
}			t_info;

/*
**************************** PRINTF MAIN *********************************
*/

int		ft_printf(const char *content, ...);
void	init_parsing(va_list ap, const char *content, t_info *info);
void	parse_flag(const char *content, t_info *info, va_list ap);
void	init_info(t_info *info);
void	check_width_prec(const char *content, t_info *info, va_list ap);
void	parse_type(va_list ap, t_info *info);

/*
 ******************************* LIBFT ***********************************
 */

int		ft_isdigit(int c);
int		ft_putchar(char c, t_info *info);
int		ft_strchr(const char *s, int c, t_info *info);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2, int free_str);
int		ft_putstr(char *str, t_info *info);

/*
 **************************** PRINT TYPE **********************************
 */

void	print_c_percent(int c, t_info *info);
void	print_s(char *s, t_info *info);
void	print_nb(unsigned long long nb, t_info *info);
int		ft_nblen(unsigned long long nb, t_info *info);
char	*nb_string(int nb_len, unsigned long long nb, t_info *info);
char	*ft_baseset(char type);
void	print_nb2(unsigned long long nb, char *nb_s, int nb_len, t_info *info);
void	print_nb3(unsigned long long nb, char *nb_s, t_info *info);

#endif
