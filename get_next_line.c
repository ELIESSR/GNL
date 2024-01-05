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
	while (!strs || (!ft_strchr(strs, '\n') && rb > 0))
	{
		rb = read(fd, aux, BUFFER_SIZE);
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

char	*ft_printer(char **s)
{
	char	*r;
	char	*aux;
	int		i;

	i = 0;
	aux = *s;
	while (*s && (*s)[i] && (*s)[i] != '\n')
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

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
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

/* int main()
{
	int fd = open("only_nl.txt", O_RDONLY);
	char *manolo;

 	while(manolo)
	{
		manolo = get_next_line(fd);
		printf("%s", manolo);
	} 
	manolo = get_next_line(fd);
	printf("%s", manolo);
	manolo = get_next_line(fd);
	printf("%s", manolo);
	manolo = get_next_line(fd);
	printf("%s", manolo);
	manolo = get_next_line(fd);
	printf("%s", manolo);
	manolo = get_next_line(fd);
	printf("%s", manolo);
	close(fd);
	return 0;
} */