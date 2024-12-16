/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   isometric.c                                    .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/11 14:25:33 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/16 22:13:34 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_2d_point	iso_project(t_3d_point point, t_data data)
{
	t_2d_point	projected;
	int			line_multiplier;

	line_multiplier = (data.win_w / 2) / data.map.width;
	point.x *=line_multiplier;
	point.y *=line_multiplier;
	point.z *=line_multiplier;

	projected.color = point.color;
	projected.y = (data.win_h / 3) - (point.z / 20) - (point.x * sin(60)) - (point.y * sin(60));
	projected.x = (data.win_w / 2) - (point.x * cos(60)) + (point.y * cos(60));
	return (projected);
}
