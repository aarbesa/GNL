/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:57:09 by aabdyli           #+#    #+#             */
/*   Updated: 2022/12/23 14:59:03 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char		*str[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_txt(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = main_line(str[fd]);
	str[fd] = leftover_char(str[fd]);
	return (line);
}
