/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   fdf.c                                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/23 12:11:44 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/11/23 12:22:25 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(void)
{
	void *ctx;
	void *win;

	ctx = mlx_init();
	win= mlx_new_window(ctx, 800, 800, "Hello world");
	draw_line(ctx, win, 400, 400, 400, 500, 4294967295);
}
