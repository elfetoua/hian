# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 17:31:33 by hiantrin          #+#    #+#              #
#    Updated: 2019/06/23 13:15:00 by hiantrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

head = *.o

$(NAME): 
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(head)
	ranlib $(NAME)

all : $(NAME)

clean:
	/bin/rm -f $(head)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all



