/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   sandbox.c                                      .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/26 16:21:13 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/02 19:15:33 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argn, char **arg)
{
	int i = 0;
	int	line = 0;
	t_map map;
	
	if (argn <= 1)
		return (1);
	map = read_map(arg[1]);
	while (map.h_grid[line])
	{
		while (i < map.size)
		{
			printf("%d ", map.c_grid[line][i].g);
			i++;
		}
		printf("\n");
		line ++;
		i = 0;
	}
}
