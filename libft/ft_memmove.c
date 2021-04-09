/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:03:33 by saelee            #+#    #+#             */
/*   Updated: 2021/03/30 21:03:35 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char *s;
	unsigned char		*d;

	s = src;
	d = dst;
	if (s > d)
		while (len-- > 0)
			*(d++) = *(s++);
	else if (s < d)
		while (len-- > 0)
			*(d + len) = *(s + len);
	return (dst);
}
