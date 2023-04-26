
NAME	= Cub3D

SRC		= main.c errors.c libft_tools.c get_next_line.c get_next_line_utils.c parsing.c\
		identifiers.c iden_tools.c libft_tools1.c tools0.c map.c map_check.c Leak_Hunter/leak_hunter.c \
		Leak_Hunter/list_tools.c ft_free.c

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