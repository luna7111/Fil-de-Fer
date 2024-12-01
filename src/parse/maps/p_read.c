/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   p_read.c                                       .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/01 11:30:58 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/01 16:15:32 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//move to utils pls
int	array_size(char **array)
{
	int i;
	
	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	count_valid_lines(char *file)
{
	int	lines;
	int fd;
	char *line;

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

int	*line_to_array(char *line)
{
	int	i;
	int *array;
	char **split_line;
	
	i = 0;
	split_line = ft_split(line, ' ');
	array = malloc(array_size(split_line) * sizeof(int));
	while (split_line[i] != NULL)
	{
		array[i] = ft_atoi(split_line[i]);
		i++;
	}
	free(split_line);
	return (array);
}

grid	read_map(char *file)
{
	char	*raw_line;
	int		fd;
	int		line;
	grid	map;

	fd = open(file, O_RDONLY);
	map = malloc(count_valid_lines(file) * (sizeof(int *) + 1));
	raw_line = get_next_line(fd);
	while (raw_line)
	{
		map[line] = line_to_array(raw_line);
		free(raw_line),
		raw_line = get_next_line(fd);
		line++;
	}
	map[line] = NULL;
	return (map);
}
