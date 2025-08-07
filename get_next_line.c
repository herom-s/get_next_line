/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:51:42 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 19:18:07 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_break_rest(char **rest)
{
	char	*tmp_rest;
	char	*start;
	char	*end;
	char	*line;

	tmp_rest = NULL;
	start = *rest;
	end = *rest;
	while (*end && *end != '\n')
		end++;
	if (*end != '\0')
	{
		tmp_rest = ft_strdup(end + 1);
		line = ft_substrp(start, start, (end - start) + 1);
	}
	else
	{
		tmp_rest = ft_strdup("");
		line = ft_substrp(start, start, (end - start));
	}
	free(*rest);
	*rest = tmp_rest;
	return (line);
}

void	ft_free_rest(char **rest)
{
	free(*rest);
	*rest = NULL;
}

char	*ft_get_line(int fd, char **rest, char *buffer)
{
	int		bytes_read;
	char	*tmp_rest;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free_rest(rest), NULL);
		buffer[bytes_read] = '\0';
		tmp_rest = ft_strjoin(*rest, buffer);
		free(*rest);
		*rest = tmp_rest;
		if (ft_strchr(*rest, '\n'))
			return (ft_break_rest(rest));
	}
	if (bytes_read == 0 && *(*rest) != '\0')
	{
		tmp_rest = *rest;
		*rest = NULL;
		return (tmp_rest);
	}
	return (ft_free_rest(rest), NULL);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (rest)
			ft_free_rest(&rest);
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!rest)
		rest = ft_strdup("");
	if (!rest)
		return (free(buffer), NULL);
	line = ft_get_line(fd, &rest, buffer);
	if (!line)
		return (free(buffer), NULL);
	return (free(buffer), line);
}
