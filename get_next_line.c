/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:50:57 by aabdyli           #+#    #+#             */
/*   Updated: 2022/12/22 17:29:50 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_txt(char *str, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (!check_newline(str, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buffer[i] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = ft_read_txt(leftover, fd);
	if (!leftover)
		return (NULL);
	line = main_line(leftover);
	leftover = leftover_char(leftover);
	return (line);
}
