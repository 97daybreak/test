/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:05:21 by saelee            #+#    #+#             */
/*   Updated: 2021/03/30 21:05:22 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *t;

	t = NULL;
	while (*s)
		if (*s++ == c)
			t = s - 1;
	if (!c)
		return ((char*)s);
	return ((char*)t);
}
