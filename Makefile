# **************************************************************************** #
#                                                                              #
#                                                     _.._  .           .      #
#    Makefile                                       .' .-'`        *           #
#                                                  /  /       +        *       #
#    By: ldel-val <ldel-val@42madrid.com>          |  |           *            #
#                                                  \  '.___.;       +          #
#    Created: 2024/11/25 12:45:41 by ldel-val       '._  _.'   .        .      #
#    Updated: 2024/12/25 21:12:59 by ldel-val          ``                      #
#                                                                              #
# **************************************************************************** #

#Compiler and linker
CC 		:=	cc

#Remove tool
RM 		:=	rm -f

#Flags
MLX		:=	mlx/libmlx.a
LIBFT	:=	libft/libft.a
CFLAGS 	:=	-Wall -Wextra -Werror -O3 -Isrc/headers
LIB 	:=	-Lmlx -lmlx -lXext -lX11 -lm $(LIBFT)

#Project stuff 

NAME 	:=	fdf
SRC 	:=	src/fdf.c src/hooks.c\
			src/parsing/fdf_to_map.c src/parsing/map_to_list.c src/parsing/aux.c\
			src/projection/isometric.c\
			src/rendering/drawing.c\
			src/utils/color_conversion.c src/utils/free_memory.c src/utils/misc.c
OBJ		:=	$(SRC:.c=.o)

#-----------------------------------------------------------------------------#
#                                    Rules                                    #
#-----------------------------------------------------------------------------#

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C mlx

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) 

clean:
	$(MAKE) -C libft fclean
	$(MAKE) -C mlx clean
	$(RM) $(OBJ)

fclean:
	$(MAKE) -C libft fclean
	$(MAKE) -C mlx clean
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
