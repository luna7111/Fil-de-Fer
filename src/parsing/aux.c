/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   aux.c                                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/05 17:26:26 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/05 18:14:41 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	get_map_width(char **map)
{
	int		width;
	char	**split_line;

	split_line = ft_split(map[0], ' ');
	width = 0;
	while (split_line[width])
		width++;
	free_split(split_line);
	return (width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
