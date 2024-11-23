/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   draw_line.c                                    .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/23 12:08:32 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/11/23 12:15:17 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(void *ctx, void *win, int x1, int y1, int x2, int y2, int color)
{
	int i;

	while (i < 100)
	{
		mlx_pixel_put(ctx, win, x1 + 1, y1 + i, color);
		mlx_pixel_put(ctx, win, x2 + 1, y2 + i, color);
		i++;
	}
}
