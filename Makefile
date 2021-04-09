# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saelee <saelee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 21:07:52 by saelee            #+#    #+#              #
#    Updated: 2021/04/09 15:05:43 by saelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printer.c ft_cs.c ft_diopux.c ft_efg.c ft_spec.c ft_n.c

OBJ	= $(SRC:.c=.o)

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
			cd libft && $(MAKE)
			cp libft/libft.a $(NAME)
			ar rc  $(NAME) $(OBJ)
			ranlib $(NAME)

all:		$(NAME)

bonus	:	all

clean:
			$(RM) $(OBJ) $(OBJ_B)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			$(RM) libft.a
			$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY: bonus all clean fclean re
