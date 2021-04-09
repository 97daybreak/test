/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:04:23 by saelee            #+#    #+#             */
/*   Updated: 2021/03/30 21:04:25 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *s, char c)
{
	char	**mem;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s || !(mem = malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < ft_wordcount(s, c))
	{
		while (s[k] == c)
			k++;
		j = 0;
		while (s[k + j] != c && s[k + j])
			j++;
		if (!(mem[i] = malloc(sizeof(char) * (j + 1))))
			return (NULL);
		ft_memcpy(mem[i], s + k, j);
		mem[i][j] = 0;
		i++;
		k += j;
	}
	mem[i] = NULL;
	return (mem);
}
