
NAME	= Cub3D

SRC		= main.c map_errors.c libft_tools.c get_next_line.c get_next_line_utils.c parsing.c

FLAGS	= -Wall -Werror -Wextra -g #

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