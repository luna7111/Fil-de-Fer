# **************************************************************************** #
#                                                                              #
#                                                     _.._  .           .      #
#    Makefile                                       .' .-'`        *           #
#                                                  /  /       +        *       #
#    By: ldel-val <ldel-val@student.42madrid.com>  |  |           *            #
#                                                  \  '.___.;       +          #
#    Created: 2024/11/23 11:51:54 by ldel-val       '._  _.'   .        .      #
#    Updated: 2024/11/23 21:30:44 by ldel-val          ``                      #
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
# Name of the sandbox program
SANDBOX_NAME = sandbox
# Name of the sandbox c file
SANDBOX = src/sandbox.c
# Source files (aside from main and sandbox);
SRC = src/draw_line.c\
src/color.c\
src/inits.c
# Convert all .c files to .o
OBJ = $(SRC:.c=.o)


# Compiler
CC = cc
# Compiler flags
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT) -I$(MLX)
# Archiver
AR = ar
# Archiver flags
ARFLAGS = -rc

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ) $(MAINFILE)
	$(AR) $(ARFLAGS) $(LIBNAME) $(OBJ)
	$(CC) $(CFLAGS) -L$(MLX) -lmlx -lXext -lX11 $(MAINFILE) $(LIBNAME) $(LIBMLX) $(LIBFTLIB) -o $(NAME)

sandbox: $(MLX) $(LIBFT) $(OBJ) $(SANDBOX)
	$(AR) $(ARFLAGS) $(LIBNAME) $(OBJ)
	$(CC) $(CFLAGS) -L$(MLX) -lmlx -lXext -lX11 $(SANDBOX) $(LIBNAME) $(LIBMLX) $(LIBFTLIB) -o $(SANDBOX_NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBNAME) $(NAME) $(SANDBOX_NAME)

$(MLX):
	$(MAKE) -C $(MLX)

$(LIBFT):
	$(MAKE) -C $(LIBFT)
