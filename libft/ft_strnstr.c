/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:05:16 by saelee            #+#    #+#             */
/*   Updated: 2021/03/30 21:05:17 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack && len-- > 0)
	{
		j = 0;
		while (haystack[j] == needle[j] && j++ <= len)
			if (!needle[j])
				return ((char*)haystack);
		haystack++;
	}
	return (0);
}
