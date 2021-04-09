/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:07:05 by saelee            #+#    #+#             */
/*   Updated: 2021/04/09 18:58:35 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct	s_n
{
	long long int	*arg;
	long long int	nchr;
	struct s_n		*prev;
	struct s_n		*next;
}				t_n;

typedef struct	s_con
{
	char			sign;
	char			adj;
	char			padd;
	char			alt;
	int				width;
	int				pre;
	char			len;
	char			spec;
}				t_con;

long long int	ft_linkn(t_n *current);
t_con			*ft_initialize(void);
void			ft_flager(const char **str, t_con *cs);
void			ft_lenth(const char **str, t_con *cs);
t_n				*ft_newn(t_n *prev, int nchr);
int				ft_printer(t_con *cs, char *s);
int				ft_printf(const char *str, ...);
void			ft_save_n(t_n **n, va_list args, t_con *cs);
int				ft_spec_c(t_con *cs, char c);
int				ft_spec_u(t_con *cs, unsigned long long int num);
int				ft_spec_di(t_con *cs, long long int num);
int				ft_spec_efg(t_con *cs, long double f);
int				ft_spec_o(t_con *cs, unsigned long long int num);
int				ft_spec_px(t_con *cs, unsigned long long int num);
int				ft_spec_s(t_con *cs, char *s);
void			ft_width_pre(const char **str, t_con *cs, va_list args);

#endif
