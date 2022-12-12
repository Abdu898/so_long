
NAME = so_long

# BONUS = 

SRC = handle_error.c so_long.c

# SRC_BONUS = 

CC = cc

CFLAGS = -Wall -Werror -Wextra

COMPILE = $(CC) $(CFLAGS)

FT_PRINTF = ./ft_printf/libftprintf.a

MLX = ./mlx/libmlx.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@make -C ./mlx
	@make -C ./ft_printf
	$(CC) $(SRC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit $(FT_PRINTF) $(MLX) -o $(NAME)

# bonus:
# 	@make -C ./mlx
# 	@make -C ./ft_printf
# 	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# 	@$(COMPILE) $(SRC) $(FT_PRINTF) -o $(NAME)

clean:
	@make clean -C ./mlx
	@make clean -C ./ft_printf

fclean:	clean
	@make clean -C ./mlx
	@make fclean -C ./ft_printf
	@rm -f $(NAME) $(BONUS)

re: fclean all

# rebo: fclean all bonus

.PHONY: all clean fclean re bonus rebo
