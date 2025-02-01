/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:39:00 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 23:10:52 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_newline(int fd, char **temp_buf)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!*temp_buf)
	{
		*temp_buf = ft_strdup("");
		if (!*temp_buf)
			return (free(buffer), NULL);
	}
	bytes_read = 1;
	while (!ft_strchr(*temp_buf, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(*temp_buf), NULL);
		buffer[bytes_read] = '\0';
		*temp_buf = ft_strjoin_and_free(*temp_buf, buffer);
		if (!*temp_buf)
			return (free(buffer), NULL);
	}
	return (free(buffer), *temp_buf);
}

char	*extract_line(char *temp_buf)
{
	size_t	i;
	char	*line;

	if (!temp_buf || *temp_buf == '\0')
		return (NULL);
	i = 0;
	while (temp_buf[i] && temp_buf[i] != '\n')
		i++;
	if (temp_buf[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strncpy(line, temp_buf, i);
	return (line);
}

char	*update_temp_buf(char *temp_buf)
{
	size_t	i;
	size_t	len;
	char	*new_temp_buf;

	i = 0;
	while (temp_buf[i] && temp_buf[i] != '\n')
		i++;
	if (temp_buf[i] == '\0')
		return (free(temp_buf), NULL);
	len = ft_strlen(temp_buf);
	new_temp_buf = (char *)malloc(len - i + 1);
	if (!new_temp_buf)
		return (free(temp_buf), NULL);
	ft_strcpy(new_temp_buf, temp_buf + i + 1);
	return (free(temp_buf), new_temp_buf);
}

char	*get_next_line(int fd)
{
	static char	*temp_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_until_newline(fd, &temp_buf))
		return (NULL);
	line = extract_line(temp_buf);
	temp_buf = update_temp_buf(temp_buf);
	return (line);
}
