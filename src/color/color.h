/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   color.h                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/11/26 15:32:11 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/11/26 16:04:01 by ldel-val          ``                     */
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

int	rgbatoi(t_rgba rgba);
#endif
