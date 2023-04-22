
NAME	= Cub3D

SRC		= main.c errors.c libft_tools.c get_next_line.c get_next_line_utils.c parsing.c\
		identifiers.c iden_tools.c libft_tools1.c tools0.c 

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