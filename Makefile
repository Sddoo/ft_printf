# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 16:31:47 by hfrankly          #+#    #+#              #
#    Updated: 2019/05/22 20:40:14 by hfrankly         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

FLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_printf.c srcs/main.c srcs/parser.c srcs/puts.c

INCLUDES = -I includes -I libft

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) $(INCLUDES) -L libft -lft -g -o $(NAME)

fclean: 
	if [ -a $(NAME) ] ; \
	then \
		/bin/rm $(NAME) ; \
	fi;

re: fclean all
