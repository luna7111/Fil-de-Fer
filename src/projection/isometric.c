/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   isometric.c                                    .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/11 14:25:33 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/15 17:41:09 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_2d_point	iso_project(t_3d_point point)
{
	t_2d_point	projected;
	
	point.x *=10;
	point.y *=10;
	point.z *=10;

	projected.color = point.color;
	projected.y = 500 - point.z - (point.x * sin(60)) - (point.y * sin(60));
	projected.x = 500 - (point.x * cos(60)) + (point.y * cos(60));
	return (projected);
}
