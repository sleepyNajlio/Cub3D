
NAME	= Cub3D

SRC			= main.c parsing/errors.c parsing/libft_tools.c parsing/get_next_line.c parsing/get_next_line_utils.c parsing/parsing.c\
			parsing/identifiers.c parsing/iden_tools.c parsing/libft_tools1.c parsing/tools0.c parsing/map.c parsing/map_check.c\
			parsing/ft_free.c hooks.c draw_2d.c 

FLAGS		= -Wall -Werror -Wextra -g 

FRAMEWORK	= -framework OpenGL -framework AppKit

CC			= cc

all : $(NAME)

$(NAME) : $(SRC)
	@make all -C ./mlx
	@$(CC) $(FLAGS) $(SRC) $(FRAMEWORK) ./mlx/libmlx.a -o $(NAME)
	@echo "✅"

clean :
	@make clean -C ./mlx
	@rm -f $(NAME)
	@echo "❌"
	
fclean : clean

re : fclean all