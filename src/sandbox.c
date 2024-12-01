/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   sandbox.c                                      .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/26 16:21:13 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/01 23:11:10 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(void)
{
	int i = 0;
	int	line = 0;
	char file[] = "/home/luna/github/raw-fdf/examples/maps/test_maps/basictest.fdf";
	grid map;

	map = read_map(file);
	while (line < 9)
	{
		while (i < 11)
		{
			printf("%d ", map[line][i]);
			i ++;
		}
		printf("\n");
		line ++;
		i = 0;
	}
}
