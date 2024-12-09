/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   2d.c                                           .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/08 16:47:03 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/09 19:32:38 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw_pixel(void *ctx, void *win, t_2d_point pixel)
{
	mlx_pixel_put(ctx, win, pixel.x, pixel.y, rgba_to_int(pixel.color));
}

t_rgba	get_gradient_pixel(t_2d_line line, t_2d_point pixel, int hv)
{
	t_rgba	color;
	float	weight;

	if (hv == 1)
		weight = (float)(pixel.x - line.p1.x) / (line.p2.x -  line.p1.x);
	else
		weight = (float)(pixel.y - line.p1.y) / (line.p2.y -  line.p1.y);
	color.r = (line.p1.color.r * weight) + (line.p2.color.r * (1 - weight));
	color.g = (line.p1.color.g * weight) + (line.p2.color.g * (1 - weight));
	color.b = (line.p1.color.b * weight) + (line.p2.color.b * (1 - weight));
	color.a = (line.p1.color.a * weight) + (line.p2.color.a * (1 - weight));
	return (color);
}

void	draw_line(void *ctx, void *win, t_2d_line line)
{
		float		dx = line.p2.x - line.p1.x;
		float		dy = line.p2.y - line.p1.y;
		t_2d_point	pixel;
		float			slope;

		if (fabs(dx) >= fabs(dy))
		{
			if	(line.p1.x > line.p2.x)
				swap_line(&line);
			pixel.x = line.p1.x;
			pixel.y = line.p1.y;
			slope = (float)(line.p2.y - line.p1.y) / (line.p2.x - line.p1.x);
			while (pixel.x <= line.p2.x)
			{
				pixel.color = get_gradient_pixel(line, pixel, 1);
				draw_pixel(ctx, win, pixel);
				pixel.x ++;
				pixel.y = line.p1.y + ((pixel.x - line.p1.x) * slope);
			}
		} else {
			if	(line.p1.y > line.p2.y)
				swap_line(&line);
			pixel.x = line.p1.x;
			pixel.y = line.p1.y;
			slope = (float)(line.p2.x - line.p1.x) / (line.p2.y - line.p1.y);
			while (pixel.y <= line.p2.y)
			{
				pixel.color = get_gradient_pixel(line, pixel, 0);
				draw_pixel(ctx, win, pixel);
				pixel.y ++;
				pixel.x = line.p1.x + ((pixel.y - line.p1.y) * slope);
			}
		}
}

int	main(void)
{
	void	*ctx = mlx_init();
	void	*win = mlx_new_window(ctx, 1000, 1000, "test");
	t_2d_line line;
	
	line.p1.color.r = 255;
	line.p1.color.g = 0;
	line.p1.color.b = 0;
	line.p1.color.a = 255;

	line.p1.color.r = 0;
	line.p1.color.g = 255;
	line.p1.color.b = 0;
	line.p1.color.a = 255;

	line.p1.x = 0;
	line.p1.y = 0;
	line.p2.x = 1000;
	line.p2.y = 1000;

	draw_line(ctx, win, line);
	while (1);
}
