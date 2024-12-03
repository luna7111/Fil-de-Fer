/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   maps.h                                         .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/01 11:31:18 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/03 12:46:58 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

typedef	struct s_map {
	int		 size;
	int 	**h_grid;
	t_rgba	**c_grid;
}	t_map;

int		*line_to_array(char *line, int size);
t_map	read_map(char *file); 
