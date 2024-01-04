/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:51:49 by elteran           #+#    #+#             */
/*   Updated: 2024/01/03 19:06:40 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_line(int fd, char *strs)
{
	char	*aux;
	char	*copy;
	int		rb;

	rb = 1;
	aux = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (NULL);
	while (!strs || (!ft_strchr(strs, '\n') && rb != 0))
	{
		rb = read(fd, aux, BUFFER_SIZE); /*menos averigua dios y perdona*/
		if (rb == -1)
		{
			free(aux);
			free(strs);
			return (NULL);
		}
		aux[rb] = '\0';
		copy = strs;
		strs = ft_strjoin_gnl(strs, aux);
		free(copy);
	}
	free(aux);
	return (strs);
}

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	aux = read_line(fd, aux);
	if (!aux || !aux[0])
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	result = ft_printer(&aux);
	return (result);
}

char	*ft_printer(char **s)
{
	char	*r;
	char	*aux;
	int		i;

	i = 0;
	aux = *s;
	while (*s && (*s)[i] && (*s)[i] != '\n')//no entiendo bien
		i++;
	if ((*s) && (*s)[i] == '\n')
		i++;
	r = ft_substr_gnl(*s, 0, i);
	*s = ft_substr_gnl(*s, i, ft_strlen_gnl((const char *)*s));
	if (!*s)
		free(*s);
	free(aux);
	if (!r[0])
	{
		free(r);
		r = NULL;
	}
	return (r);
}

/*int	main(void)
{
	char	*f1;
	int		fd;
	char	*str;

	f1 = "prueba.txt";
	fd = open(f1, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
		free(str);
	}
	system("leaks -q a.out");
	return (0);
}*/
