/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:51:09 by aabdyli           #+#    #+#             */
/*   Updated: 2022/12/23 15:04:20 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read_txt(char *str, int fd);
char	*ft_strjoin_gnl(char *s1, char *buffer);
size_t	ft_strlen(char *str);
int		check_newline(char *str, char c);
char	*main_line(char *str);
char	*leftover_char(char *str);

#endif
