/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:07:44 by saelee            #+#    #+#             */
/*   Updated: 2021/04/09 15:05:29 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_n				*ft_newn(t_n *prev, int nchr)
{
	t_n		*new;

	if (!(new = malloc(sizeof(t_n))))
		return (NULL);
	new->prev = prev;
	new->arg = NULL;
	new->nchr = nchr;
	new->next = NULL;
	return (new);
}

long long int	ft_linkn(t_n *current)
{
	long long int n;

	n = current->nchr;
	while (current->prev)
		current = current->prev;
	while (current->arg)
	{
		*(current->arg) = current->nchr;
		current = current->next;
		free(current->prev);
	}
	free(current);
	current = NULL;
	return (n);
}

void			ft_save_n(t_n **n, va_list args, t_con *cs)
{
	if (cs->len == 'H')
		(*n)->arg = (long long int*)va_arg(args, int*);
	else if (cs->len == 'h')
		(*n)->arg = (long long int*)va_arg(args, int*);
	else if (!cs->len)
		(*n)->arg = (long long int*)va_arg(args, int*);
	else if (cs->len == 'l')
		(*n)->arg = (long long int*)va_arg(args, long int*);
	else if (cs->len == 'L')
		(*n)->arg = (long long int*)va_arg(args, long long int*);
	(*n)->next = ft_newn(*n, (*n)->nchr);
	*n = (*n)->next;
}
