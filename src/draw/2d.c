/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                           .' .-'`        *          */
/*                                                    +:+ +:+         +:+     */
/*   By: ldel-val <ldel-val@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:47:03 by ldel-val          #+#    #+#             */
/*   Updated: 2024/12/18 20:49:14 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	l_draw_pixel(t_data *data, t_2d_point pixel)
{
	mlx_pixel_put(data->ctx, data->win, pixel.x, pixel.y, rgba_to_int(pixel.color));
}

void	draw_pixel(t_data *data, char *img_addr, t_2d_point pixel)
{
	char *dst;

	if (pixel.x < 0 || pixel.y < 0 || pixel.x > data->win_w || pixel.y > data->win_h)
		return ;
	dst = img_addr + (pixel.y * data->img_l_len + pixel.x * (data->img_bpp / 8));
	*(unsigned int*)dst = rgba_to_int(pixel.color);
}

t_rgba	get_gradient_pixel(t_2d_line line, t_2d_point pixel, int hv)
{
	t_rgba	color;
	float	weight;
	


	if (hv == 1)
		weight = (float)(pixel.x - line.p1.x) / (line.p2.x -  line.p1.x);
	else
		weight = (float)(pixel.y - line.p1.y) / (line.p2.y -  line.p1.y);
	color.r = (line.p2.color.r * weight) + (line.p1.color.r * (1 - weight));
	color.g = (line.p2.color.g * weight) + (line.p1.color.g * (1 - weight));
	color.b = (line.p2.color.b * weight) + (line.p1.color.b * (1 - weight));
	color.a = (line.p2.color.a * weight) + (line.p1.color.a * (1 - weight));
	return (color);
}

void	draw_line(t_data *data, t_2d_line line)
{
		float		dx = line.p2.x - line.p1.x;
		float		dy = line.p2.y - line.p1.y;
		t_2d_point	pixel;
		float		slope;

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
				draw_pixel(data, data->img_addr, pixel);
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
				draw_pixel(data, data->img_addr, pixel);
				pixel.y ++;
				pixel.x = line.p1.x + ((pixel.y - line.p1.y) * slope);
			}
		}
}

t_3d_point init_3d(int x, int y, int z, int r, int g, int b)
{
	t_3d_point point;
	point.x = x;
	point.y = y;
	point.z = z;
	point.color.r = r;
	point.color.g = g;
	point.color.b = b;
	return (point);
}
