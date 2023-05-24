
GREEN_COLOR = \033[0;32m

NAME	= Cub3D

SRC			= main.c parsing/errors.c parsing/libft_tools.c parsing/get_next_line.c parsing/get_next_line_utils.c parsing/parsing.c\
			parsing/identifiers.c parsing/iden_tools.c parsing/libft_tools1.c parsing/tools0.c parsing/map.c parsing/map_check.c\
			parsing/ft_free.c draw_2d.c raycasting/initiallize.c raycasting/draw.c raycasting/hooks.c raycasting/hooks_utils.c\
			raycasting/raycasting.c

FLAGS		= -Wall -Werror -Wextra -g 

FRAMEWORK	= -framework OpenGL -framework AppKit

CC			= cc

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -lmlx -framework OpenGL -framework appKit -o $(NAME)
	@echo "${GREEN_COLOR}Compiling done !"

clean :
	@rm -f $(NAME)
	@echo "❌"
	
fclean : clean

re : fclean all