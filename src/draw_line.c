/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   draw_line.c                                    .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/23 12:08:32 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/11/24 16:00:52 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(void *ctx, void *win, t_line line, int color)
{
	int dx;
	int dy;

	dx = line.x2 - line.x1;
	dy = line.y2 - line.y1;
	if	(dx >= 0)
	{
		if (dy < dx)
	}
			
}
