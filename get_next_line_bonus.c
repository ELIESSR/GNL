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
#include "get_next_line_bonus.h"

void ft_leaks(void)
{
	system("leaks -q a.out");
}

char	*read_line(int fd, char *strs)
{
	char	*aux;
	char	*copy;
	int		rb;

	rb = 1;
	aux = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//printf("Esta es la dirección de aux%p\n", aux);
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
	static char	*aux[4096];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux[fd] = read_line(fd, aux[fd]);
	if (!aux[fd])
	{
		free(aux[fd]);
		aux[fd] = NULL;
		return (NULL);
	}
	result = ft_printer(&aux[fd]);
	return (result);
}

/* int main()
{
	int fd = open("only_nl.txt", O_RDONLY);
	char *manolo;

	atexit(ft_leaks);
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
