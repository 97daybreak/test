/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sjofree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:04:15 by saelee            #+#    #+#             */
/*   Updated: 2021/03/30 21:04:17 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sjofree(char *s1, char *s2, short int fr)
{
	char	*s;

	if (!s1 || !s2 || fr < 0 || fr > 3)
		return (NULL);
	s = ft_strjoin(s1, s2);
	if (fr == 1 || fr == 3)
	{
		free(s1);
		s1 = NULL;
	}
	if (fr == 2 || fr == 3)
	{
		free(s2);
		s2 = NULL;
	}
	return (s);
}
