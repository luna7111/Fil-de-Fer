/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   inits.c                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/23 21:18:24 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/11/23 21:41:23 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_rgba	init_rgba(int r, int g, int b, int a)
{
	t_rgba rgba;

	rgba.r = r;
	rgba.g = g;
	rgba.b = b;
	rgba.a = a;
	return (rgba);
}

t_line init_line(int x1, int y1, int x2, int y2)
{
	t_line	line;

	line.x1 = x1;
	line.y1 = y1;
	line.x2 = x2;
	line.y2 = y2;
	line.slope = (float)(y2 - y1) / (x2 - x1);
	printf("%f", line.slope);
	return (line);
}
