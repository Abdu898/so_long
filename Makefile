
NAME = so_long

SRC = handle_error.c map_read.c map_check.c so_long.c \
		load_textures.c render_image.c dfs.c key_events.c

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

COMPILE = $(CC) $(CFLAGS)

FT_PRINTF = ./ft_printf/libftprintf.a

MLX = ./mlx/libmlx.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@make -C ./mlx
	@make -C ./ft_printf
	@$(CC) $(SRC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit $(FT_PRINTF) $(MLX) -o $(NAME)

clean:
	@make clean -C ./mlx
	@make clean -C ./ft_printf

fclean:	clean
	@make clean -C ./mlx
	@make fclean -C ./ft_printf
	@rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus rebo
