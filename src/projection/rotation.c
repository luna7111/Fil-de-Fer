/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   rotation.c                                     .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/02/05 15:37:51 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/02/06 14:58:35 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_3d_point	rotate(t_3d_point point, t_data data)
{
	t_3d_point	rot;
	t_3d_point	buf_z;
	t_3d_point	buf_y;

	point.x = point.x - (data.map.width / 2);
	point.y = point.y - (data.map.height / 2);

	buf_z.z = point.z;
	buf_z.y = (float)(point.y * cos(data.rot_z)) - (point.x * sin(data.rot_z));
	buf_z.x = (float)(point.x * cos(data.rot_z)) + (point.y * sin(data.rot_z));

	buf_y.y = buf_z.y;
	buf_y.x = (float)(buf_z.x * cos(data.rot_y)) - (buf_z.z * sin(data.rot_y));
	buf_y.z = (float)(buf_z.z * cos(data.rot_y)) + (buf_z.x * sin(data.rot_y));

	rot.x = buf_y.x;
	rot.z = (float)(buf_y.z * cos(data.rot_x)) - (buf_y.y * sin(data.rot_x));
	rot.y = (float)(buf_y.y * cos(data.rot_x)) + (buf_y.z * sin(data.rot_x));
	rot.color = point.color;
	return (rot);
}
