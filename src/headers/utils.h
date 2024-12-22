/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   utils.h                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/05 17:49:29 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/22 14:35:10 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define L_HEX "0123456789abcdef"
# define U_HEX "0123456789ABCDEF"

int		rgba_to_int(t_rgba rgba);
t_rgba	hex_to_rgba(char *hex);
int		hex_digit_to_int(char digit, char *base);

t_rgba	init_rgba(int r, int g, int b, int a);

void	free_map(t_map *map);
void	free_split(char **split);

void	swap(int *a, int *b);
void	swap_line(t_2d_line *line);

#endif
