/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   color.c                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/23 18:10:10 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/11/23 20:18:17 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int rgbatoi(t_rgba rgba)
{
	int mlx_color;

	mlx_color = rgba.a;
	mlx_color = mlx_color << 8;
	mlx_color += rgba.r;
	mlx_color = mlx_color << 8;
	mlx_color += rgba.g;
	mlx_color = mlx_color << 8;
	mlx_color += rgba.b;
	return (mlx_color);
}
