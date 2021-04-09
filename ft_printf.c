/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:06:59 by saelee            #+#    #+#             */
/*   Updated: 2021/04/09 14:54:27 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find2(t_con *cs, t_n **n, va_list args)
{
	if (cs->spec == 'p')
		(*n)->nchr += ft_spec_px(cs, (unsigned long int)va_arg(args, void*));
	else if ((cs->spec == 'x' || cs->spec == 'X') && cs->len == 'H')
		(*n)->nchr += ft_spec_px(cs, (unsigned char)va_arg(args, int));
	else if ((cs->spec == 'x' || cs->spec == 'X') && cs->len == 'h')
		(*n)->nchr += ft_spec_px(cs, (unsigned short int)va_arg(args, int));
	else if ((cs->spec == 'x' || cs->spec == 'X') && !cs->len)
		(*n)->nchr += ft_spec_px(cs, (unsigned int)va_arg(args, int));
	else if ((cs->spec == 'x' || cs->spec == 'X') && cs->len == 'l')
		(*n)->nchr += ft_spec_px(cs, (unsigned long int)va_arg(args, long int));
	else if ((cs->spec == 'x' || cs->spec == 'X') && cs->len == 'L')
		(*n)->nchr += ft_spec_px(cs,
		(unsigned long long int)va_arg(args, long long int));
	else if ((cs->spec == 'f' || cs->spec == 'e' || cs->spec == 'g')
	&& !cs->len)
		(*n)->nchr += ft_spec_efg(cs, (double)va_arg(args, double));
	else if ((cs->spec == 'f' || cs->spec == 'e' || cs->spec == 'g')
	&& cs->len == 'L')
		(*n)->nchr += ft_spec_efg(cs, (long double)va_arg(args, long double));
	else if (cs->spec == 'n')
		ft_save_n(n, args, cs);
	else
		return (-1);
	return (0);
}

int		ft_find1(t_con *cs, t_n **n, va_list args)
{
	if ((cs->spec == 'd' || cs->spec == 'i') && cs->len == 'H')
		(*n)->nchr += ft_spec_di(cs, (signed char)va_arg(args, int));
	else if ((cs->spec == 'd' || cs->spec == 'i') && cs->len == 'h')
		(*n)->nchr += ft_spec_di(cs, (short int)va_arg(args, int));
	else if ((cs->spec == 'd' || cs->spec == 'i') && !cs->len)
		(*n)->nchr += ft_spec_di(cs, (int)va_arg(args, int));
	else if ((cs->spec == 'd' || cs->spec == 'i') && cs->len == 'l')
		(*n)->nchr += ft_spec_di(cs, (long int)va_arg(args, long int));
	else if ((cs->spec == 'd' || cs->spec == 'i') && cs->len == 'L')
		(*n)->nchr += ft_spec_di(cs, (long long int)
		va_arg(args, long long int));
	else if (cs->spec == 'o' && cs->len == 'H')
		(*n)->nchr += ft_spec_o(cs, (unsigned char)va_arg(args, int));
	else if (cs->spec == 'o' && cs->len == 'h')
		(*n)->nchr += ft_spec_o(cs, (unsigned short int)va_arg(args, int));
	else if (cs->spec == 'o' && !cs->len)
		(*n)->nchr += ft_spec_o(cs, (unsigned int)va_arg(args, int));
	else if (cs->spec == 'o' && cs->len == 'l')
		(*n)->nchr += ft_spec_o(cs, (unsigned long int)va_arg(args, long int));
	else if (cs->spec == 'o' && cs->len == 'L')
		(*n)->nchr += ft_spec_o(cs, (unsigned long long int)
		va_arg(args, long long int));
	else
		return (ft_find2(cs, n, args));
	return (0);
}

int		ft_find(t_con *cs, t_n **n, va_list args)
{
	if (cs->spec == '%')
		(*n)->nchr += ft_spec_c(cs, '%');
	else if (cs->spec == 'c')
		(*n)->nchr += ft_spec_c(cs, (char)va_arg(args, int));
	else if (cs->spec == 's')
		(*n)->nchr += ft_spec_s(cs, va_arg(args, char*));
	else if (cs->spec == 'u' && cs->len == 'H')
		(*n)->nchr += ft_spec_u(cs, (unsigned char)va_arg(args, int));
	else if (cs->spec == 'u' && cs->len == 'h')
		(*n)->nchr += ft_spec_u(cs, (unsigned short int)va_arg(args, int));
	else if (cs->spec == 'u' && !cs->len)
		(*n)->nchr += ft_spec_u(cs, (unsigned int)va_arg(args, int));
	else if (cs->spec == 'u' && cs->len == 'l')
		(*n)->nchr += ft_spec_u(cs, (unsigned long int)va_arg(args, long int));
	else if (cs->spec == 'u' && cs->len == 'L')
		(*n)->nchr += ft_spec_u(cs, (unsigned long long int)
		va_arg(args, long long int));
	else
		return (ft_find1(cs, n, args));
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	t_n			*n;
	t_con	*cs;

	va_start(args, str);
	n = ft_newn(NULL, 0);
	while (*str)
	{
		if (*str != '%' && (n->nchr += 1))
			write(1, str++, 1);
		else if (*str++)
		{
			cs = ft_initialize();
			ft_flager(&str, cs);
			ft_width_pre(&str, cs, args);
			ft_lenth(&str, cs);
			if (ft_find(cs, &n, args) < 0)
				return (-1);
			free(cs);
			cs = NULL;
		}
	}
	va_end(args);
	return (ft_linkn(n));
}
