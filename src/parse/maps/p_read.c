/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   p_read.c                                       .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/01 11:30:58 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/02 19:08:03 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//move to utils pls
int	array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	count_valid_lines(char *file)
{
	int		lines;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines ++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

int	get_map_size(char *file)
{
	int		size;
	int		fd;
	char	*line;
	char	**split_line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	size = 0;
	while (split_line[size])
		size ++;
	free(line);
	free(split_line);
	close(fd);
	return (size);
}

//deprecated
int	*line_to_h_array(char *line, int size)
{
	int		i;
	int		*array;
	char	**split_line;

	i = 0;
	split_line = ft_split(line, ' ');
	array = malloc(size * sizeof(int));
	while (split_line[i] != NULL && i < size)
	{
		array[i] = ft_atoi(split_line[i]);
		i++;
	}
	while (i < size)
	{
		array[i] = 0;
		i ++;
	}
	free(split_line);
	return (array);
}

//to utils!!!
t_rgba	ahex_to_rgb(char *hex, char *base)
{
	t_rgba	color;
	int		i;

	i = 0;
	if (!hex || !base)
		return (ahex_to_rgb("0xFFFFFF", "0123456789ABCDEF"));
	if (!ft_strncmp(hex, "0x", 2))
		i += 2;
	color.r = 0;
	color.r += (ft_strchr(base, hex[i]) - base) * 16;
	i ++;
	color.r += ft_strchr(base, hex[i]) - base;
	i ++;
	color.g = 0;
	color.g += (ft_strchr(base, hex[i]) - base) * 16;
	i ++;
	color.g += ft_strchr(base, hex[i]) - base;
	i ++;
	color.b = 0;
	color.b += (ft_strchr(base, hex[i]) - base) * 16;
	i ++;
	color.b += ft_strchr(base, hex[i]) - base;
	color.a = 255;
	return (color);
}

//protect mallocs!
int	parse_line(t_map map, int line_number, char *line)
{
	int		i;
	char	**split_line;
	char	**vertex;
	split_line = ft_split(line, ' ');
	map.h_grid[line_number] = malloc(map.size * sizeof(int));
	map.c_grid[line_number] = malloc(map.size * sizeof(t_rgba));
	i = 0;
	while (split_line[i] != NULL && i < map.size)
	{
		vertex = ft_split(split_line[i], ',');
		map.h_grid[line_number][i] = ft_atoi(vertex[0]);
		map.c_grid[line_number][i] = ahex_to_rgb(vertex[1], "0123456789ABCDEF");
		i++;
	}
	while (i < map.size)
	{
		map.h_grid[line_number][i] = 0;
		map.c_grid[line_number][i] = ahex_to_rgb("0xFFFFFF", "0123456789ABCDEF");
	}
	return (1);
}

t_map	read_map(char *file)
{
	t_map	map;
	char	*raw_line;
	int		fd;
	int		line;

	map.size = get_map_size(file);
	map.h_grid = malloc(count_valid_lines(file) * (sizeof(int *) + 1));
	map.c_grid = malloc(count_valid_lines(file) * (sizeof(t_rgba *) + 1));
	line = 0;
	fd = open(file, O_RDONLY);
	raw_line = get_next_line(fd);
	while (raw_line)
	{
		parse_line(map, line, raw_line);
		free(raw_line);
		line ++;
		raw_line = get_next_line(fd);
	}
	return (map);
}
