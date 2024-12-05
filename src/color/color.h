/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   color.h                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/26 15:32:11 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/04 17:52:21 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_rgba
{
    int a;
    int r;
    int g;
    int b;
}   t_rgba;

int		rgba_to_int(t_rgba rgba);
t_rgba	hex_to_rgba(char *hex);
int		hex_digit_to_int(char digit, char *base);

t_rgba	init_rgba(int r, int g, int b, int a);

#endif
