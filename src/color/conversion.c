/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   conversion.c                                   .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/25 16:45:42 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/11/26 12:32:57 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.c>

int *rgbtoi(t_rgb rgb)
{
	int color;

	color = rgb.a;
	color << 8;
	color += rbg.r;
	color << 8;
	color += rbg.g;
	color << 8;
	color += rbg.b;
	return (color);
}
