/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charlloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:00:57 by saelee            #+#    #+#             */
/*   Updated: 2021/03/30 21:00:59 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_charlloc(size_t len, char c)
{
	void *s;

	if (!(s = malloc(len + 1)))
		return (NULL);
	ft_bchar(s, len, c);
	return (s);
}
