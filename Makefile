# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 16:31:47 by hfrankly          #+#    #+#              #
#    Updated: 2019/06/14 17:56:58 by hfrankly         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_printf.c srcs/parser.c srcs/puts.c srcs/csp.c srcs/diouxX.c srcs/conversions.c srcs/f.c 

OBJS = ft_printf.o parser.o puts.o csp.o diouxX.o conversions.o f.o

INCLUDES = -I includes -I libft

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) srcs/main.c $(INCLUDES) -L./libft -lft -g -o printf
	gcc $(FLAGS) -c $(SRCS) $(INCLUDES)
	ar -x libft/libft.a
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm -rf *.o

clean:
	/bin/rm -f *.o *~

fclean: 
	if [ -a $(NAME) ] ; \
	then \
		/bin/rm $(NAME) ; \
	fi;

re: fclean all
