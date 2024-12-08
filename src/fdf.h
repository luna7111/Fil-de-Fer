/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   fdf.h                                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/26 12:34:16 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/08 16:53:09 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

# include "color/color.h"
# include "parse/maps/maps.h"
# include "utils/utils.h"

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
#endif
