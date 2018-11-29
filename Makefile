NAME	=	libftprintf.a

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o		:	%.c	./ft_printf.h	./Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	rm -f	$(OBJ)

fclean	: clean
	rm -f	$(NAME)

re		:	fclean all
