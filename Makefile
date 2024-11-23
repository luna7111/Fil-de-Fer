# **************************************************************************** #
#                                                                              #
#                                                     _.._  .           .      #
#    Makefile                                       .' .-'`        *           #
#                                                  /  /       +        *       #
#    By: ldel-val <ldel-val@student.42madrid.com>  |  |           *            #
#                                                  \  '.___.;       +          #
#    Created: 2024/11/23 11:51:54 by ldel-val       '._  _.'   .        .      #
#    Updated: 2024/11/23 12:24:49 by ldel-val          ``                      #
#                                                                              #
# **************************************************************************** #

# Name and path of the mlx
LIBMLX = mlx/libmlx.a
MLX = mlx

# Name and path of the libft
LIBFTLIB = libft/libft.a
LIBFT = libft

# Name of the program file
NAME = fdf
# Name of the main library
LIBNAME = fdf.a
# Name of the main file
MAINFILE = src/fdf.c
# Name of the sandbox file
SANDBOX = src/sandbox.c
# Source files (aside from main and sandbox);
SRC = src/draw_line.c
# Convert all .c files to .o
OBJ = $(SRC:.c=.o)


# Compiler
CC = cc
# Compiler flags
CFLAGS = -Wall -Wextra -Werror -L $(MLX) -lmlx -lXext -lX11
# Archiver
AR = ar
# Archiver flags
ARFLAGS = -rc

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(AR) $(ARFLAGS) $(LIBNAME) $(OBJ)
	$(CC) $(CFLAGS) $(MAINFILE) $(LIBNAME) $(LIBMLX) $(LIBFTLIB) -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX)

$(LIBFT):
	$(MAKE) -C $(LIBFT)
