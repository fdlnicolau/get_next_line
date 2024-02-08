/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:13:17 by lnicolau          #+#    #+#             */
/*   Updated: 2024/02/08 13:46:16 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			store;
	size_t			i;

	store = count * size;
	ptr = malloc(store);
	if (!ptr)
		return (0);
	i = 0;
	while (i < store)
		ptr[i++] = 0;
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;

	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	substring = (char *)ft_calloc(len + 1, sizeof(char));
	if (!substring)
		return (0);
	i = 0;
	while (i < len)
		substring[i++] = s[start ++];
	return (substring);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*concatenation;
	int		i;
	int		j;

	i = -1;
	j = 0;
	concatenation = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1,
			sizeof(char));
	if (concatenation == NULL)
		return (0);
	while (s1[++i])
		concatenation[i] = s1[i];
	while (s2[j])
		concatenation[i++] = s2[j++];
	free (s1);
	return (concatenation);
}
