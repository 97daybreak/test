/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:07:10 by saelee            #+#    #+#             */
/*   Updated: 2021/04/08 18:36:46 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_spec_c(t_con *cs, char c)
{
	int		padd;

	padd = 0;
	if (cs->adj == '-')
		write(1, &c, 1);
	while (++padd < cs->width)
		if (cs->padd == '0' && !cs->adj)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	if (!cs->adj)
		write(1, &c, 1);
	return (padd);
}

int			ft_spec_s(t_con *cs, char *s)
{
	int		padd;
	int		len;

	s = !s ? "(null)" : s;
	len = ft_strlen(s);
	len = cs->pre >= 0 && cs->pre < len ? cs->pre : len;
	if (cs->adj == '-')
		write(1, s, len);
	padd = 0;
	while (cs->width-- > len && ++padd)
		write(1, &cs->padd, 1);
	if (!cs->adj)
		write(1, s, len);
	return (len + padd);
}
