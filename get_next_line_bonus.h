/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:57:26 by aabdyli           #+#    #+#             */
/*   Updated: 2022/12/23 15:05:13 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 666
# endif

char	*get_next_line(int fd);
char	*ft_read_txt(char *str, int fd);

char	*ft_strjoin_gnl(char *s1, char *buffer);
size_t	ft_strlen(char *str);
int		check_newline(char *str, char c);

char	*main_line(char *str);
char	*leftover_char(char *str);

#endif
