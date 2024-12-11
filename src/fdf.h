/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   fdf.h                                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/26 12:34:16 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/11 17:27:25 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

# include "color/color.h"
# include "parse/maps/maps.h"

typedef struct s_3d_point
{
	float	x;
	float	y;
	float	z;
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

# include "utils/utils.h"
# include "projection/projections.h"

#endif
