/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   isometric.c                                    .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/11 14:25:33 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/11 18:26:31 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_2d_point	iso_project(t_3d_point point)
{
	t_2d_point	projected;
	
	printf("iso_project input: x %f, y %f, z %f\n", point.x, point.y, point.z);

	projected.color = point.color;
	projected.y = 500 + (cos(60) * point.z) + (point.x * sin(60)) + (point.y * sin(60));
	projected.x = 500 + (point.x * cos(60)) - (point.y * cos(60));
	printf("projected coordinates: x %d, y %d\n", projected.x, projected.y);
	return (projected);
}
