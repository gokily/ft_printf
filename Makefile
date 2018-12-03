# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 12:50:46 by gly               #+#    #+#              #
#    Updated: 2018/12/03 16:05:07 by gly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_conv_c.c	\
			ft_conv_d.c	\
			ft_conv_f.c	\
			ft_conv_o.c	\
			ft_conv_p.c	\
			ft_conv_per.c	\
			ft_conv_s.c	\
			ft_conv_u.c	\
			ft_conv_x.c	\
			ft_ll2a_pf.c	\
			ft_addlpf_per.c	\
			ft_addlpf_str.c	\
			ft_lst_manipulators.c	\
			ft_printf.c	\
			ft_utils.c	\

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFTDIR	=	./libft

LIBFT	=	libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBFT)
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(LIBFT)	:
	make -C $(LIBFTDIR)

%.o		:	%.c	./ft_printf.h	./Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	rm -f	$(OBJ)

fclean	: clean
	rm -f	$(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
