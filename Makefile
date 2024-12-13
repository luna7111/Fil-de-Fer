# **************************************************************************** #
#                                                                              #
#                                                     _.._  .           .      #
#    Makefile                                       .' .-'`        *           #
#                                                  /  /       +        *       #
#    By: ldel-val <ldel-val@42madrid.com>          |  |           *            #
#                                                  \  '.___.;       +          #
#    Created: 2024/11/25 12:45:41 by ldel-val       '._  _.'   .        .      #
#    Updated: 2024/12/13 17:18:46 by ldel-val          ``                      #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SANDBOX_NAME = sandbox

CC = cc

CFLAGS = -Wall -Wextra -Werror -Isrc

LIB_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm

RM = rm -f

HEADER = src/fdf.h

SRC = 	src/parse/maps/fdf_to_map.c\
		src/parse/maps/map_to_list.c\
		src/parse/maps/aux\
		src/draw_2d.c\
		src/color/conversion.c\
		src/utils/free_things.c

OBJ = $(SRC:.c=.o)

MAIN = src/fdf.c

MAIN_OBJ = $(MAIN:.c=.o)

SANDBOX = src/sandbox.c

SANDBOX_OBJ = $(SANDBOX:.c=.o)

LIBFT = libft

MLX = mlx

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

$(NAME): $(OBJ)
