/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   p_read.c                                       .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/04 09:35:37 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/04 18:33:57 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
//obviously, this is just for testing
int main(int argn, char **arg)
{
	t_map map;
	int fd;
	
	if (argn < 2)
		return (0);
	fd = open(arg[1], O_RDONLY);
	if (fd == -1)
		return (0);
	map = parse_map(fd);
	printf("%d\n", map.width);
}

//you dont belong here...
void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}

int	get_map_width(char **map)
{
	int width;
	char **split_line;

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

void	parse_point(t_map map, char *raw_point, int x, int y)
{
	char **split_point;
	ft_printf("Raw point: %s\n", raw_point);
	split_point = ft_split(raw_point, ',');
	map.h_grid[x][y] = ft_atoi(split_point[0]);
	if	(split_point[1])
		map.c_grid[x][y] = hex_to_rgba(split_point[1]);
	else
		map.c_grid[x][y] = init_rgba(255, 255, 255, 255);
	free_split(split_point);
}

void	parse_line(t_map map, char *line, int y)
{
	char **split_line;
	int	x;
	
	split_line = ft_split(line, ' ');
	x = 0;
	while (x < map.width)
	{
		parse_point(map, split_line[x], x, y);
		x ++;
	}
	free_split(split_line);
}

t_map	parse_map(int fd)
{
	t_map	map;
	char	**raw_map;
	int		y;

	raw_map = split_file(fd);
	map.width = get_map_width(raw_map);
	map.height = get_map_height(raw_map);
	y = 0;
	while (y < map.height)
	{
			parse_line(map, raw_map[y], y);
			y ++;
	}
	return (map);
}
