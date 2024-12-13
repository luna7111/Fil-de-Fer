/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                           .' .-'`        *          */
/*                                                    +:+ +:+         +:+     */
/*   By: ldel-val <ldel-val@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:47:03 by ldel-val          #+#    #+#             */
/*   Updated: 2024/12/13 18:54:05 by ldel-val          ``                     */
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
	color.r = (line.p2.color.r * weight) + (line.p1.color.r * (1 - weight));
	color.g = (line.p2.color.g * weight) + (line.p1.color.g * (1 - weight));
	color.b = (line.p2.color.b * weight) + (line.p1.color.b * (1 - weight));
	color.a = (line.p2.color.a * weight) + (line.p1.color.a * (1 - weight));
	return (color);
}

void	draw_line(void *ctx, void *win, t_2d_line line)
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

int	main(int argn, char **arg)
{
	void	*ctx = mlx_init();
	void	*win = mlx_new_window(ctx, 1000, 1000, "test");
	t_line_list	list;
	t_map map;

	parse_map(&map, open(arg[1], O_RDONLY));
	list = map_to_list(map);
	
	int i = 0;
	t_2d_line line;
	printf("%d\n", list.size);
	while (i < list.size)
	{
		printf("%d\n", i);
		line.p1 = iso_project(list.lines[i].p1);
		line.p2 = iso_project(list.lines[i].p2);
		draw_line(ctx, win, line);
		i++;
	}

	while (1);
}
