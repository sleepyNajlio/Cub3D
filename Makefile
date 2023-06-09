
GREEN_COLOR = \033[0;32m

NAME		= Cub3D

SRC			= src/main.c src/parsing/errors.c src/parsing/libft_tools.c src/parsing/get_next_line.c src/parsing/get_next_line_utils.c src/parsing/parsing.c\
			src/parsing/identifiers.c src/parsing/iden_tools.c src/parsing/libft_tools1.c src/parsing/tools0.c src/parsing/map.c src/parsing/map_check.c\
			src/parsing/ft_free.c src/draw_2d.c src/raycasting/initiallize.c src/raycasting/draw.c src/hooks.c src/hooks_utils.c src/hooks_utils1.c src/parsing/map_tools.c\
			src/raycasting/raycasting.c src/raycasting/hor_rays.c src/raycasting/render_3d.c src/raycasting/utils.c src/raycasting/ver_rays.c

FLAGS		= -Wall -Werror -Wextra

FRAMEWORK	= -framework OpenGL -framework AppKit 

CC			= cc

all : $(NAME)

$(NAME) : $(SRC)
	@make all -C ./mlx
	@$(CC) $(FLAGS) $(SRC) $(FRAMEWORK) ./mlx/libmlx.a -o $(NAME)
	@echo "${GREEN_COLOR}Compiling done !"

clean :
	@rm -f $(NAME)
	@echo "❌"
	
fclean : clean

re : fclean all