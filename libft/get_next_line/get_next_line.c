/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:40:13 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/13 13:04:47 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*alloc_add(char *buf, char *line, int size_to_add)
{
	char		*result;
	int			i;
	int			len_line;

	i = 0;
	len_line = len(line);
	result = null_str(len_line + size_to_add);
	if (!result)
		return (free(line), NULL);
	while (line[i])
	{
		result[i] = line[i];
		i++;
	}
	i = 0;
	while (i < size_to_add)
	{
		result[len_line + i] = buf[i];
		i++;
	}
	free(line);
	return (result);
}

void	buf_clean(char *buf)
{
	char	*ptr;
	int		final_len;
	int		i;

	i = 0;
	ptr = strchr(buf, '\n');
	final_len = len(ptr) - 1;
	ft_memmove(buf, ptr + 1, final_len);
	while (i < BUFFER_SIZE - final_len)
	{
		buf[final_len + i] = '\0';
		i++;
	}
}

char	*buf_check(int bytes_count, int fd, char *buf, char *line)
{
	while (bytes_count > 0)
	{
		if (buf[0] == 0)
			bytes_count = read(fd, buf, BUFFER_SIZE);
		if (strchr(buf, '\n'))
		{
			line = alloc_add(buf, line, len(buf) - len(strchr(buf, '\n')) + 1);
			if (!line)
				return (NULL);
			buf_clean(buf);
			if (line[0] == '\0')
				return (free(line), NULL);
			return (line);
		}
		else
		{
			line = alloc_add(buf, line, len(buf));
			if (!line)
				return (NULL);
			ft_bzero(buf, BUFFER_SIZE + 1);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1] = "\0";
	char			*line;
	int				bytes_count;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd < 0)
		return (ft_bzero(buf, BUFFER_SIZE + 1), NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = 0;
	bytes_count = 1;
	return (buf_check(bytes_count, fd, buf, line));
}
