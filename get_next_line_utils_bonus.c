/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:55:17 by elteran           #+#    #+#             */
/*   Updated: 2024/01/03 19:07:16 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;

	c1 = c;
	while (*s != '\0' && *s != c1)
		s++;
	if (*s == c1)
		return ((char *)s);
	return (NULL);
}

/* char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
    free(s1);
	return (str);
} */

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof (char));
	if (str == (0))
		return (0);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
		str[i + j] = s2[j];
	str[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;


	i = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen_gnl(s);
	if (len > slen - start)
		len = slen - start;
	if (start >= slen)
		return (ft_strdup_gnl(""));
	sub = malloc(sizeof(char) * (slen + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup_gnl(const char *s1)
{
	char		*dup;
	size_t		i;
	size_t		slengh;

	i = 0;
	slengh = ft_strlen_gnl(s1);
	dup = malloc(sizeof(char) * slengh + 1);
	if (dup == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
