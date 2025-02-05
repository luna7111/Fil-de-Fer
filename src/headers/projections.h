/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   projections.h                                  .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/11 17:04:19 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/02/05 15:45:04 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTIONS_H
# define PROJECTIONS_H

t_3d_point	rotate(t_3d_point point, t_data data);
t_2d_point	iso_project(t_3d_point point, t_data data);

#endif
