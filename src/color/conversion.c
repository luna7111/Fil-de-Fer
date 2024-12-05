/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   conversion.c                                   .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/25 16:45:42 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/05 16:14:24 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	rgba_to_int(t_rgba rgba)
{
	int color;

	color = rgba.a;
	color = color << 8;
	color += rgba.r;
	color = color << 8;
	color += rgba.g;
	color = color << 8;
	color += rgba.b;
	return (color);
}

//doesnt belong here
int	hex_digit_to_int(char digit, char *base)
{
	return (ft_strchr(base, digit) - base);
}

//doesnt belong here
t_rgba	init_rgba(int r, int g, int b, int a)
{
	t_rgba	rgba;

	rgba.r = r;
	rgba.g = g;
	rgba.b = b;
	rgba.a = a;
	return (rgba);
}

int	check_hex(char *string, char *base)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!ft_strchr(base, string[i]))
			return (0);
		i++;
	}
	if (i == 6)
		return (1);
	return (0);
}

t_rgba	hex_to_rgba(char *hex)
{
	t_rgba	color;

	if (!ft_strncmp(hex, "0x", 2))
		hex += 2;
	if (!check_hex(hex, "0123456789ABCDEF"))
		return (init_rgba(255, 255, 255, 255));
	color = init_rgba(0,0,0,255);
	color.r	+= hex_digit_to_int(*hex, "0123456789ABCDEF") * 16;
	hex++;
	color.r += hex_digit_to_int(*hex, "0123456789ABCDEF");
	hex++;
	color.g	+= hex_digit_to_int(*hex, "0123456789ABCDEF") * 16;
	hex++;
	color.g += hex_digit_to_int(*hex, "0123456789ABCDEF");
	hex++;
	color.b	+= hex_digit_to_int(*hex, "0123456789ABCDEF") * 16;
	hex++;
	color.b += hex_digit_to_int(*hex, "0123456789ABCDEF");
	return (color);
}
