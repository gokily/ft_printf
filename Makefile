# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 12:50:46 by gly               #+#    #+#              #
#    Updated: 2019/01/10 11:51:29 by gly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_conv_c.c	\
			ft_conv_d.c	\
			ft_conv_f.c	\
			ft_conv_o.c	\
			ft_conv_b.c	\
			ft_conv_p.c	\
			ft_conv_per.c	\
			ft_conv_s.c	\
			ft_conv_u.c	\
			ft_conv_x.c	\
			ft_ll2a_pf.c	\
			ft_atoi_pf.c	\
			ft_addlpf_per.c	\
			ft_addlpf_str.c	\
			ft_lst_manipulators.c	\
			ft_printf.c	\
			ft_utils.c	\

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

LIBFTDIR	=	./libft

LIBFT	=	$(LIBFTDIR)/libft.a

all		: $(NAME)

$(NAME)	: $(LIBFT) $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(LIBFT) :
	make -C libft
	cp $(LIBFT) $(NAME)

%.o		:	%.c	./ft_printf.h	./ft_convtab.h	./Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	make -C $(LIBFTDIR) clean
	rm -f	$(OBJ)

fclean	: clean
	rm -f	$(NAME) $(LIBFT)

re		:	fclean all

.PHONY	:	all clean fclean re
