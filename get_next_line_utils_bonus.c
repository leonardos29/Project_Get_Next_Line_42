/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:29:23 by leonasil          #+#    #+#             */
/*   Updated: 2025/05/20 18:53:06 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
		new[i++] = s2[k++];
	new[i] = '\0';
	free(s1);
	return (new);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;
	size_t			size_max;
	size_t			i;

	size_max = (size_t)-1;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size && nmemb > size_max / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
		ptr[i++] = 0;
	return ((void *)ptr);
}

int	is_error(ssize_t result, char *buff, char *rest)
{
	if (result < 0)
	{
		free(buff);
		free(rest);
		return (1);
	}
	return (0);
}
