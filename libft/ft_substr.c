/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:05:31 by saelee            #+#    #+#             */
/*   Updated: 2021/03/30 21:05:33 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	str[len + 1];
	size_t	slen;

	if (!s)
		return (NULL);
	if (start > (slen = ft_strlen(s)))
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	ft_memcpy(str, s + start, len + 1);
	str[len] = 0;
	return (ft_strdup(str));
}
