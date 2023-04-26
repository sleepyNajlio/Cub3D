
NAME	= Cub3D

SRC		= main.c parsing/errors.c parsing/libft_tools.c parsing/get_next_line.c parsing/get_next_line_utils.c parsing/parsing.c\
		parsing/identifiers.c parsing/iden_tools.c parsing/libft_tools1.c parsing/tools0.c parsing/map.c parsing/map_check.c\
		Leak_Hunter/leak_hunter.c Leak_Hunter/list_tools.c parsing/ft_free.c

FLAGS	= -Wall -Werror -Wextra -g 

CC		= cc

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "✅"

clean :
	@rm -f $(NAME)
	@echo "❌"
	
fclean : clean

re : fclean all