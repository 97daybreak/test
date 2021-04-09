/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_efg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:07:28 by saelee            #+#    #+#             */
/*   Updated: 2021/04/09 18:59:05 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_alternative(t_con *cs, int *len, int *dot, int *i)
{
	if (*len == *dot + (!cs->alt ? 1 : 2))
		*len = *dot + (!cs->alt ? 0 : 2);
	*i = !cs->alt ? 1 : 2;
	*len = *len == *dot + *i ? *dot + *i : *len;
	*i = *len - 1;
	cs->alt = 0;
}

long double	ft_dv(int ifg)
{
	long double	div;

	div = 1;
	while (ifg)
	{
		div = ifg < 0 ? div / 10 : div * 10;
		ifg < 0 ? ifg++ : ifg--;
	}
	return (div);
}

int			ft_ifg(t_con *cs, int ifg)
{
	char	s[((ifg > 99 || ifg < -99) ? 3 : 2) + 3];
	int		i;
	int		j;
	char	spec;

	if (cs->spec == 'f' || cs->spec == 'j')
		return (0);
	s[0] = 'e';
	s[1] = ifg < 0 ? '-' : '+';
	ifg = ifg < 0 ? -(ifg) : ifg;
	i = (ifg > 99 ? 3 : 2) + 2;
	s[i] = 0;
	j = 2;
	while (j-- > 0 || ifg)
	{
		s[--i] = (char)((ifg % 10) + 48);
		ifg /= 10;
	}
	spec = cs->spec;
	cs = ft_initialize();
	cs->spec = spec;
	return (ft_printer(cs, s));
}

int			ft_base(t_con *cs, long double f, int len, int ifg)
{
	char		s[len + 1];
	int			dot;
	int			i;

	i = 0;
	s[i++] = '0';
	1 / f < 0 ? cs->sign = '-' : 1;
	f = (1 / f < 0 ? -f : f) / ft_dv((cs->spec == 'f' || cs->spec == 'j') &&
	ifg < 0 ? 0 : ifg);
	while (i < len - 1 && (s[i++] = (char)f + 48))
		f = (f - (int)f) * 10;
	if ((f > 5 || (f == 5 && s[i - 1] % 2)) && i--)
		while ((s[i] = s[i] == '9' ? '0' : (s[i]) + 1) == '0')
			i--;
	dot = s[0] == '0' ? 2 : 1;
	dot += ((cs->spec == 'f' || cs->spec == 'j') && ifg >= 0 ? ifg : 0);
	if ((cs->spec == 'a' || cs->spec == 'j') && !cs->alt)
		while (len - 2 >= dot && s[len - 2] == '0')
			len--;
	ft_alternative(cs, &len, &dot, &i);
	while (i > dot && i--)
		s[i + 1] = s[i];
	s[dot] = '.';
	s[len] = 0;
	return (ft_printer(cs, s[0] == '0' ? &s[1] : s));
}

int			ft_spec_efg(t_con *cs, long double f)
{
	short int	ifg;
	long double	ff;
	short int	len;

	ifg = 0;
	ff = 1 / f < 0 ? -f : f;
	while ((ff >= 10 && ++ifg) || (ff < 1 && --ifg))
		ff = ff < 1 ? ff * 10 : ff / 10;
	cs->pre = cs->pre < 0 ? 6 : cs->pre;
	cs->pre = cs->spec == 'g' && cs->pre > 0 ? cs->pre - 1 : cs->pre;
	len = 1 + cs->pre + (cs->spec == 'f' ? ifg : 0);
	ff = (1 / f < 0 ? -f : f) / ft_dv(ifg);
	while (ff >= 9 && len--)
		ff = (ff - (int)ff) * 10;
	ifg += len <= 0 && ff >= 5 ? 1 : 0;
	if (cs->spec == 'g')
		cs->spec = ifg < -4 || ifg > cs->pre ? 'a' : 'j';
	len = cs->pre + 3;
	len += cs->spec == 'f' && ifg > 0 ? ifg : 0;
	len -= cs->spec == 'j' && ifg < 0 ? ifg : 0;
	if (cs->spec == 'a' || cs->spec == 'e')
		cs->width -= ifg > 99 || ifg < -99 ? 5 : 4;
	return (ft_base(cs, f, len, ifg) + ft_ifg(cs, ifg));
}
