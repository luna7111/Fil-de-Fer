/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldel-val <ldel-val@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:25:27 by ldel-val          #+#    #+#             */
/*   Updated: 2024/12/13 18:06:32 by ldel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_3d_line	new_hline(t_map map, t_2d_point current)
{
	t_3d_line	line;

	line.p1.x = current.x;
	line.p1.y = current.y;
	line.p1.z = map.h_grid[current.y][current.x];
	line.p1.color = map.c_grid[current.y][current.x];
	line.p2.x = current.x + 1;
	line.p2.y = current.y;
	line.p2.z = map.h_grid[current.y][current.x + 1];
	line.p2.color = map.c_grid[current.y][current.x + 1];
	return (line);
}

t_3d_line	new_vline(t_map map, t_2d_point current)
{
	t_3d_line	line;

	line.p1.x = current.x;
	line.p1.y = current.y;
	line.p1.z = map.h_grid[current.y][current.x];
	line.p1.color = map.c_grid[current.y][current.x];
	line.p2.x = current.x;
	line.p2.y = current.y + 1;
	line.p2.z = map.h_grid[current.y + 1][current.x];
	line.p2.color = map.c_grid[current.y + 1][current.x];
	return (line);
}
t_line_list map_to_list(t_map map)
{
	t_line_list	lines;
	t_2d_point	current;
	
	current.y = 0;
	current.x = 0;
	lines.lines = malloc(2 * map.width * map.height * sizeof(t_3d_line));
	lines.size = 0;
	while (current.y < map.height)
	{
		while (current.x < map.width)
		{
			if (current.x != map.width - 1)
			{
				lines.lines[lines.size] = new_hline(map, current);
				lines.size ++;
			}
			if (current.y != map.height -1)
			{
				lines.lines[lines.size] = new_vline(map, current);
				lines.size ++;
			}
			current.x ++;
		}
		current.x = 0;
		current.y ++;
	}
	return (lines);

}
