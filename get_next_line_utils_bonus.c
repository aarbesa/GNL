/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:57:49 by aabdyli           #+#    #+#             */
/*   Updated: 2022/12/23 15:03:50 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*leftover_char(char *str)
{
	char	*leftover_line;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), str = NULL, NULL);
	if (str[i] == '\n')
		i++;
	leftover_line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!leftover_line)
		return (free(str), str = NULL, NULL);
	j = 0;
	while (str[i])
		leftover_line[j++] = str[i++];
	leftover_line[j] = 0;
	return (free(str), str = NULL, leftover_line);
}

char	*main_line(char *str)
{
	char	*new_chain;
	size_t	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new_chain = malloc(sizeof(char) * (i + 2));
	if (!new_chain)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_chain[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_chain[i++] = '\n';
	new_chain[i] = '\0';
	return (new_chain);
}

int	check_newline(char *str, char c)
{
	size_t		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
		if (str[i] == c)
			return (1);
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *buffer)
{
	char	*new_chain;
	size_t	i;
	size_t	j;

	if (!s1 || !buffer)
	{
		s1 = malloc(sizeof(char) * (1));
		if (!s1)
			return (free(s1), NULL);
		s1[0] = 0;
	}
	new_chain = (char *)malloc((ft_strlen(s1) + \
	ft_strlen(buffer) + 1) * sizeof(char));
	if (new_chain == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_chain[j++] = s1[i++];
	i = 0;
	while (buffer[i])
		new_chain[j++] = buffer[i++];
	new_chain[j] = '\0';
	return (free(s1), new_chain);
}
