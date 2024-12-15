/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   fdf.c                                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/25 16:43:50 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/15 22:20:23 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	t_data data;
	
	data.ctx = mlx_init();
	data.win_w = 640;
	data.win_h = 400;
	data.mlx_new_window(ctx, data.win_w, data.win_h, FdF);
	data.img = mlx_new_image(data.ctx, data.win_w, data.win_h);
	data.img_addr = mlx_get_data_addr(data.img, &data.bpp, &data.l_len, img_endian);
}
