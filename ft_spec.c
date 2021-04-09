/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:07:36 by saelee            #+#    #+#             */
/*   Updated: 2021/04/09 19:00:23 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_con	*ft_initialize(void)
{
	t_con	*new;

	if (!(new = malloc(sizeof(t_con))))
		return (NULL);
	new->sign = 0;
	new->adj = 0;
	new->padd = ' ';
	new->alt = 0;
	new->width = 0;
	new->pre = -1;
	new->len = 0;
	new->spec = 0;
	return (new);
}

void		ft_flager(const char **str, t_con *cs)
{
	while (**str == '0' || **str == '-' || **str == ' '
	|| **str == '+' || **str == '#')
	{
		**str == '-' ? cs->adj = '-' : 1;
		**str == '0' ? cs->padd = '0' : 1;
		(**str == ' ') && (cs->sign != '+') ? cs->sign = ' ' : 1;
		**str == '+' ? cs->sign = '+' : 1;
		**str == '#' ? cs->alt = '#' : 1;
		(*str)++;
	}
}

void		ft_width_pre(const char **str, t_con *cs, va_list args)
{
	if (**str == '*' && (*str)++)
		cs->width = va_arg(args, int);
	else if (ft_isdigit(**str))
	{
		cs->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	if (cs->width < 0 && (cs->width *= -1))
		cs->adj = '-';
	if (**str == '.' && (*str)++)
	{
		if (**str == '*' && (*str)++)
			cs->pre = va_arg(args, int);
		else if (!(ft_isdigit(**str)))
			cs->pre = 0;
		else if (ft_isdigit(**str))
		{
			cs->pre = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
	}
	cs->adj == '-' ? cs->padd = ' ' : 1;
}

void		ft_lenth(const char **str, t_con *cs)
{
	if (**str == 'L' && (*str)++)
		cs->len = 'L';
	else if (**str == 'l' && (*str)++)
	{
		if (**str == 'l' && (*str)++)
			cs->len = 'L';
		else
			cs->len = 'l';
	}
	else if (**str == 'h' && (*str)++)
	{
		if (**str == 'h' && (*str)++)
			cs->len = 'H';
		else
			cs->len = 'h';
	}
	cs->spec = *(*str)++;
	!(cs->spec == 'c' || cs->spec == 's' || cs->spec == 'e' ||
	cs->spec == 'f' || cs->spec == 'g') && cs->pre >= 0 ? cs->padd = ' ' : 1;
	cs->spec == 'c' || cs->spec == 's' || cs->spec == 'u' || cs->spec == 'p' ||
	cs->spec == 'x' || cs->spec == 'X' ? cs->sign = 0 : 1;
	cs->spec == 'c' || cs->spec == 's' || cs->spec == 'd' || cs->spec == 'i' ||
	cs->spec == 'u' || cs->spec == 'p' || cs->spec == 'n' ? cs->alt = 0 : 1;
	cs->pre < 0 && (cs->spec == 'e' || cs->spec == 'f' || cs->spec == 'g') ?
	cs->pre = 6 : 1;
}
