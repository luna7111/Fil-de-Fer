/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   free_things.c                                  .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/05 17:48:11 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/18 18:07:56 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	free_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		free(map->h_grid[y]);
		free(map->c_grid[y]);
		y++;
	}
	free(map->h_grid);
	free(map->c_grid);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}
