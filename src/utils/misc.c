/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   misc.c                                         .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/09 16:24:02 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/09 16:34:00 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	swap_line(t_2d_line *line)
{
	t_2d_point buffer;
	
	buffer = line->p1;
	line->p1 = line->p2;
	line->p2 = buffer;
}
