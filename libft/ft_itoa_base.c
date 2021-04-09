/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:02:33 by saelee            #+#    #+#             */
/*   Updated: 2021/03/30 21:02:35 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, char *base)
{
	char		ret[34];
	short int	i;
	short int	neg;
	int			bsize;

	if (!base || (bsize = ft_strlen(base)) < 2)
		return ("Error, no valid base to transform 'n'");
	i = 33;
	ret[i] = 0;
	if (n < 0)
	{
		neg = 1;
		ret[--i] = base[-(n % bsize)];
		n = -(n / bsize);
	}
	while (n % bsize || n / bsize)
	{
		ret[--i] = base[n % bsize];
		n /= bsize;
	}
	if (neg == 1)
		ret[--i] = '-';
	else if (i == 33)
		ret[--i] = '0';
	return (ft_strdup(&ret[i]));
}
