# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/06 17:30:46 by jterrazz          #+#    #+#              #
#    Updated: 2017/08/06 17:39:00 by jterrazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

FILES = get_next_line.c ../libft/libft.a

OFILES = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@echo "Compilation GNL:\033[92m OK\033[0m"
	@ranlib $(NAME)
	@echo "--> Optimisation ar rc:\033[92m OK\033[0m"

%.o: %.c
	gcc -c $(FLAGS) -o $@ $< -I ../../includes

clean:
	@rm -rf $(OFILES)
	@echo "Deleting:\n\033[33m $(OFILES)\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "Deleting:\n\033[33m $(NAME)\033[0m"

re: fclean all