/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   projection.c                                   .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/11 14:25:33 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/02/06 18:33:54 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_2d_point	par_project(t_3d_point point, t_data data)
{
	t_2d_point	projected;
	float		line_multiplier;

	line_multiplier = ((data.win_w / 2) / data.map.width);
	line_multiplier *= ((float)data.zoom / 100);
	point.x *= line_multiplier;
	point.y *= line_multiplier;
	point.z *= line_multiplier;
	projected.color = point.color;
	projected.y = point.y + (data.win_h / 2);
	projected.x = point.x + (data.win_w / 2);
	return (projected);
}

t_2d_point	iso_project(t_3d_point point, t_data data)
{
	t_2d_point	projected;
	float		line_multiplier;

	line_multiplier = ((data.win_w / 2) / data.map.width);
	line_multiplier *= ((float)data.zoom / 100);
	point.x *= line_multiplier;
	point.y *= line_multiplier;
	point.z *= line_multiplier;
	projected.color = point.color;

	projected.y = data.cam_y + (data.win_h / 2);
	projected.y -= (point.z) + (point.x * sin(60)) + (point.y * sin(60));
	projected.x = data.cam_x + (data.win_w / 2);
	projected.x += (point.y * cos(60)) - (point.x * cos(60));
	return (projected);
}

t_2d_point	project(t_3d_point point, t_data data)
{
	if (data.projection == ISOMETRIC)
		return (iso_project(point, data));
	else
		return (par_project(point, data));
}
