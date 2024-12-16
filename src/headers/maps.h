/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   maps.h                                         .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/01 11:31:18 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/16 21:19:57 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

void		parse_point(t_map map, char *raw_point, int x, int y);
void		parse_line(t_map map, char *line, int y);
t_map		parse_map(int fd);

int			get_map_width(char **map);
int			get_map_height(char **map);

t_line_list map_to_list(t_map map);
#endif
