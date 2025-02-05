/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   rotation.c                                     .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/02/05 15:37:51 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/02/05 17:32:28 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_3d_point	rotate(t_3d_point point, t_data data)
{
	t_3d_point	rot;

	rot.x = point.x - (data.map.width / 2);
	rot.y = point.y - (data.map.height / 2);
	rot.z = point.z;
	rot.color = point.color;
	rot.y = (float)(rot.y * cos(data.rot_z)) - (rot.x * sin(data.rot_z));
	rot.x = (float)(rot.x * cos(data.rot_z)) + (rot.y * sin(data.rot_z));

	rot.x = (float)(rot.x * cos(data.rot_y)) - (rot.z * sin(data.rot_y));
	rot.z = (float)(rot.z * cos(data.rot_y)) + (rot.x * sin(data.rot_y));

	rot.z = (float)(rot.z * cos(data.rot_x)) - (rot.y * sin(data.rot_x));
	rot.y = (float)(rot.y * cos(data.rot_x)) + (rot.z * sin(data.rot_x));
	rot.x = rot.x + (data.map.width / 2);
	rot.y = rot.y + (data.map.height / 2);
	return (rot);
}
