NAME = fillit

LIB = libft.a

SRC = *.c

LIBSRC = libft/*.c

INCLDS = fillit.h

LIBINCLDS = libft/libft.h

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB)
			gcc $(FLAG) $(SRC) $(LIB) -o $(NAME)

$(LIB):
		gcc $(FLAG) -c $(LIBSRC) -I $(LIBINCLDS)
		ar rc $(LIB) *.o
clean:
	/bin/rm -f *.o
	/bin/rm -f .DS_Store

fclean: clean
		/bin/rm -f $(NAME)
		/bin/rm -f $(LIB)

re: fclean all
