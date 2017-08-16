NAME1 = lem-in

SRC_PATH = ./src

SRC_NAME = lem_in.c resolver.c display.c ft_utils.c check_flags.c init_flags.c \
			error.c ft_ant.c display_result.c init_links.c ft_rooms.c \
			ft_paths.c init_global_rooms.c init_global_links.c free.c \
			ft_path.c ft_paths_weight.c ft_paths_getter.c ft_path_checker.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OFILES = $(SRC_NAME:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: makelibs $(NAME1)

makelibs:
	make -C lib/libft
	make -C lib/GNL

$(NAME1): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) lib/GNL/get_next_line.a lib/libft/libft.a lib/libft/ft_printf/libftprintf.a -I includes -o $(NAME1)
	@echo "Compilation checker:\033[92m OK\033[0m"

%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I includes

clean:
	@make -C lib/GNL clean
	@make -C lib/libft clean
	@rm -rf $(OFILES)
	@echo "Deleting:\n\033[33m $(OFILES)\033[0m"

fclean: clean
	@make -C lib/GNL fclean
	@make -C lib/libft fclean
	@rm -rf $(NAME1)
	@echo "Deleting:\n\033[33m $(NAME1)\033[0m"

re : fclean all

.PHONY: all clean fclean re
