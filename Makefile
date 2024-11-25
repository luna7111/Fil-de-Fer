# **************************************************************************** #
#                                                                              #
#                                                     _.._  .           .      #
#    Makefile                                       .' .-'`        *           #
#                                                  /  /       +        *       #
#    By: ldel-val <ldel-val@42madrid.com>          |  |           *            #
#                                                  \  '.___.;       +          #
#    Created: 2024/11/25 12:45:41 by ldel-val       '._  _.'   .        .      #
#    Updated: 2024/11/25 19:27:28 by ldel-val          ``                      #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -lXext -lX11

RM = rm -f

HEADER = src/fdf.h

SRC = src/color/conversion.c

OBJ = $(SRC:.c=.o)

MAIN = src/fdf.c

MAIN_OBJ = $(MAIN:.c=.o)

SANDBOX = src/sandbox.c

SANDBOX_OBJ = $(SANDBOX:.c=.o)

LIBFT = libft

MLX = mlx

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJ) $(MAIN_OBJ) $(SANDBOX_OBJ)

fclean:
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(OBJ) $(MAIN_OBJ) $(SANDBOX_OBJ) $(NAME) $(SANDBOX)

re: fclean all

.PHONY: all re clean fclean
