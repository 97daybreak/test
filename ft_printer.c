/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:06:52 by saelee            #+#    #+#             */
/*   Updated: 2021/04/09 18:59:43 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printer(t_con *cs, char *s)
{
	int		sum;
	int		len;

	sum = 0;
	len = ft_strlen(s);
	cs->width -= cs->sign ? 1 : 0;
	cs->width -= cs->spec == 'p' || cs->alt ? 2 : 0;
	sum += cs->spec == 'p' || cs->alt ? 2 : 0;
	if (cs->sign && (cs->adj || cs->padd == '0') && ++sum)
		write(1, &cs->sign, 1);
	if ((cs->adj || cs->padd == '0') && (cs->spec == 'p' || cs->alt))
		write(1, cs->spec == 'X' ? "0X" : "0x", 2);
	if (cs->adj == '-')
		write(1, s, len);
	while (cs->width-- > len && ++sum)
		write(1, &cs->padd, 1);
	if (cs->sign && !cs->adj && cs->padd == ' ' && ++sum)
		write(1, &cs->sign, 1);
	if (!cs->adj && cs->padd == ' ' && (cs->spec == 'p' || cs->alt))
		write(1, cs->spec == 'X' ? "0X" : "0x", 2);
	if (!cs->adj)
		write(1, s, len);
	return (len + sum);
}
