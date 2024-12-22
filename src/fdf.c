/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   fdf.c                                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/25 16:43:50 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/22 14:19:04 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	gen_loading(t_data *data)
{
	t_2d_point	pixel;

	pixel.y = 0;
	pixel.color.r = 255;
	pixel.color.g = 0;
	pixel.color.b = 0;
	pixel.color.a = 128;
	while (pixel.y < data->win_h)
	{
		pixel.x = 0;
		while (pixel.x < data->win_w)
		{
			draw_pixel(data, data->lod_addr, pixel);
			pixel.x ++;
		}
		pixel.y ++;
	}
	printf("%d, %d\n", pixel.x, pixel.y);
}

void	render_map(t_data *data)
{
	int			i;
	t_2d_line	line;

	mlx_destroy_image(data->ctx, data->img);
	data->img = mlx_new_image(data->ctx, data->win_w, data->win_h);
	data->img_addr = mlx_get_data_addr(data->img, &data->img_bpp,
			&data->img_l_len, &data->img_endian);
	i = 0;
	while (i < data->list.size)
	{
		line.p1 = iso_project(data->list.lines[i].p1, *data);
		line.p2 = iso_project(data->list.lines[i].p2, *data);
		draw_line(data, line);
		i++;
	}
	mlx_put_image_to_window(data->ctx, data->win, data->img, 0, 0);
}

int	safe_close(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->ctx, data->img);
	data->img = NULL;
	free_map(&data->map);
	free(data->list.lines);
	if (data->win)
		mlx_destroy_window(data->ctx, data->win);
	data->win = NULL;
	if (data->ctx)
		mlx_destroy_display(data->ctx);
	free(data->ctx);
	data->ctx = NULL;
	exit(0);
}

void	file_init(int argn, char **arg, t_data *data)
{
	if (argn < 2 || ft_strncmp(&arg[1][ft_strlen(arg[1]) - 4], ".fdf", 4))
	{
		ft_printf("\033[0;31mMissing or incorrect filename. Abort.\n");
		exit(1);
	}
	data->fd = open(arg[1], O_RDONLY);
	if (data->fd == -1)
	{
		ft_printf("\033[0;31mCouldn't open file. Abort.\n");
		exit(1);
	}
}

int	main(int argn, char **arg)
{
	t_data	data;

	file_init(argn, arg, &data);
	data.ctx = mlx_init();
	data.win_w = 1920;
	data.win_h = 1080;
	data.zoom = 100;
	data.cam_x = 0;
	data.cam_y = 0;
	data.win = mlx_new_window(data.ctx, data.win_w, data.win_h, "FdF");
	data.img = mlx_new_image(data.ctx, data.win_w, data.win_h);
	data.img_addr = mlx_get_data_addr(data.img, &data.img_bpp, &data.img_l_len,
			&data.img_endian);
	ft_printf("\033[0;33mReading map...\n");
	data.map = parse_map(data.fd);
	ft_printf("\033[0;33mListing lines...\n");
	data.list = map_to_list(data.map);
	ft_printf("\033[0;32mReady!\033[0m");
	render_map(&data);
	mlx_hook(data.win, 17, 0, safe_close, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.ctx);
	return (0);
}
