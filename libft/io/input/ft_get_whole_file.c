/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   ft_get_whole_file.c                            .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@42madrid.com>          |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/03 15:05:21 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/07 19:09:16 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*get_whole_file(int fd)
{
	char	*file;
	char	*buffer;
	long	read_bytes;

	file = NULL;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	while (read_bytes)
	{
		file = ft_strappend(file, buffer, read_bytes);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
	}
	free(buffer);
	return (file);
}
