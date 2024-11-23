/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   sandbox.c                                      .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/23 12:11:44 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/11/23 21:33:01 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(void)
{
	void 	*ctx;
	void 	*win;
	t_rgba	color;

	ctx = mlx_init();
	win = mlx_new_window(ctx, 800, 800, "fdf");
	color.a = 255;
	color.r = 255;
	color.g = 255;
	color.b = 0;
	init_line(20, 20, 31, 41);
	draw_line(ctx, win, 400, 400, 400, 500, rgbatoi(color));
}
