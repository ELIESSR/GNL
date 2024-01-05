/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:55:07 by elteran           #+#    #+#             */
/*   Updated: 2024/01/03 19:07:32 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <ctype.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char const *s1, const char *s2);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strdup_gnl(const char *s1);
char	*ft_printer(char **s);
char	*read_line(int fd, char *strs);

#endif