/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   draw.h                                         .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/16 16:33:30 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/22 13:35:25 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

void	l_draw_pixel(t_data *data, t_2d_point pixel);
void	draw_pixel(t_data *data, char *img_addr, t_2d_point pixel);
void	draw_line(t_data *data, t_2d_line line);

void	render_map(t_data *data);

#endif
