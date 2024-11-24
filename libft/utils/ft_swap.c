/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   ft_swap.c                                      .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/24 12:40:37 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/11/24 12:44:39 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_swap_int(int *v1, int *v2)
{
	int buffer;

	if (v1 && v2)
	{
		buffer = *v1;
		*v1 = *v2;
		*v2 = buffer;
	}
}

void	ft_swap_float(float *v1, float *v2)
{
	float buffer;

	if (v1 && v2)
	{
		buffer = *v1;
		*v1 = *v2;
		*v2 = buffer;
	}
}
