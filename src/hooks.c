/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   hooks.c                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/22 12:35:12 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/22 16:08:57 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_hook(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		safe_close(data);
	if (keycode == K_LEFT)
		data->cam_x += 5;
	if (keycode == K_RIGHT)
		data->cam_x -= 5;
	if (keycode == K_UP)
		data->cam_y += 5;
	if (keycode == K_DOWN)
		data->cam_y -= 5;
	render_map(data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 4 && data->zoom < 1000)
		data->zoom += 5;
	if (keycode == 5 && data->zoom > 0)
		data->zoom -= 5;
	render_map(data);
	return (0);
}
