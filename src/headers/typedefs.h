/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   typedefs.h                                     .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/16 20:57:50 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/16 21:20:12 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct s_rgba
{
    int a;
    int r;
    int g;
    int b;
}   t_rgba;

typedef struct s_3d_point
{
	int	x;
	int	y;
	int	z;
	t_rgba	color;
}	t_3d_point;

typedef struct s_3d_line
{
	t_3d_point	p1;
	t_3d_point	p2;
}	t_3d_line;

typedef struct s_2d_point
{
	int		x;
	int 	y;
	t_rgba	color;
}	t_2d_point;

typedef struct s_2d_line
{
	t_2d_point p1;
	t_2d_point p2;
}	t_2d_line;

typedef struct s_line_list
{
	t_3d_line	*lines;
	int			size;
}	t_line_list;

typedef struct s_map
{
	int		width;
	int		height;
	int		**h_grid;
	t_rgba	**c_grid;
}	t_map;

typedef struct s_data
{
	void		*ctx;
	void		*win;
	int			win_w;
	int			win_h;
	int			fd;
	void		*img;
	char		*img_addr;
	int			img_bpp;
	int			img_l_len;
	int			img_endian;
	t_map		map;
	t_line_list list;
}	t_data;


#endif
