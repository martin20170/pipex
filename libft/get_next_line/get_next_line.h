/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:28 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/13 13:04:15 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../essentials/essentials.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		len(char *str);

void	buf_clean(char *buf);

char	*null_str(int size);
char	*get_next_line(int fd);
char	*strchr(const char *s, int c);
char	*alloc_add(char *buf, char *line, int size_to_add);
char	*buf_check(int bytes_count, int fd, char *buf, char *line);

#endif
