/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   conversion.c                                   .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/25 16:45:42 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/11/26 14:50:02 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	rgbtoi(t_rgba rgba)
{
	int color;

	color = rgba.a;
	color = color << 8;
	color += rgba.r;
	color = color << 8;
	color += rgba.g;
	color = color << 8;
	color += rgba.b;
	return (color);
}
