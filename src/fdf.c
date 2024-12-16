/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   fdf.c                                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/25 16:43:50 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/16 22:00:28 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	render_map(t_data data)
{
	int i;
	t_2d_line line;

	i = 0;
	ft_printf("\033[0;33mRendering...\n");
	while (i < data.list.size)
	{
		line.p1 = iso_project(data.list.lines[i].p1, data);
		line.p2 = iso_project(data.list.lines[i].p2, data);
		draw_line(&data, line);
		i++;
	}
	mlx_put_image_to_window(data.ctx, data.win, data.img, 0, 0);
	ft_printf("\033[0;32mImage rendered.");
}

int main(int argn, char **arg)
{
	t_data	data;

	if (argn < 2 || ft_strncmp(&arg[1][ft_strlen(arg[1]) - 4], ".fdf", 4))
	{
		ft_printf("\033[0;31mMissing or incorrect filename. Abort.\n");
		return (1);
	}
	data.fd = open(arg[1], O_RDONLY);
	if (data.fd == -1)
	{
		ft_printf("\033[0;31mCouldn't open file. Abort.\n");
		return (1);
	}
	data.ctx = mlx_init();
	data.win_w = 1920;
	data.win_h = 1250;
	data.win = mlx_new_window(data.ctx, data.win_w, data.win_h, "FdF");
	data.img = mlx_new_image(data.ctx, data.win_w, data.win_h);
	data.img_addr = mlx_get_data_addr(data.img, &data.img_bpp, &data.img_l_len, &data.img_endian);
	ft_printf("\033[0;33mReading map...\n");
	data.map = parse_map(data.fd);
	ft_printf("\033[0;33mListing lines...\n");
	data.list = map_to_list(data.map);
	render_map(data);
	mlx_loop(data.ctx);
	return (0);
}
