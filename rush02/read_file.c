/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:10:38 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/02 21:19:02 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#	define BUFFER_SIZE 1024

char	*read_file(const char *filename)
{
	int		fd;
	char	*buffer;
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
	{
		close(fd);
		return (NULL);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	close(fd);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}
