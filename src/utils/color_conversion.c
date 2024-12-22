/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   color_conversion.c                             .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/25 16:45:42 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/22 16:16:33 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	rgba_to_int(t_rgba rgba)
{
	int	color;

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
	if (!digit)
		return (0);
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

int	check_hex(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!ft_strchr(L_HEX, string[i]))
			break ;
		i++;
	}
	if (string[i])
		i = 0;
	else
		return (1);
	while (string[i])
	{
		if (!ft_strchr(U_HEX, string[i]))
			return (2);
		i ++;
	}
	return (0);
}

t_rgba	hex_to_rgba(char *hex)
{
	t_rgba	color;
	int		bytewise;
	char	*base;

	if (!ft_strncmp(hex, "0x", 2))
		hex += 2;
	if (check_hex(hex) == 0 || !*hex)
		return (hex_to_rgba("ffffff"));
	base = ft_strdup(L_HEX);
	if (check_hex(hex) == 2)
		base = ft_strdup(U_HEX);
	bytewise = 0;
	while (*hex)
	{
		bytewise = bytewise << 4;
		bytewise += hex_digit_to_int(*hex, base);
		hex ++;
	}
	color.a = 255;
	color.b = bytewise & 0xFF;
	color.g = (bytewise >> 8) & 0xFF;
	color.r = (bytewise >> 16) & 0xFF;
	return (color);
}
