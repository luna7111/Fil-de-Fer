/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   hooks.c                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/22 12:35:12 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/02/06 19:00:03 by ldel-val          ``                     */
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
	if (keycode == K_X)
		data->rot_x = fmod(data->rot_x + 0.08, M_PI * 2);
	if (keycode == K_Y)
		data->rot_y = fmod(data->rot_y + 0.08, M_PI * 2);
	if (keycode == K_Z)
		data->rot_z = fmod(data->rot_z + 0.08, M_PI * 2);
	if (keycode == K_P)
		data->projection = !data->projection;
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
