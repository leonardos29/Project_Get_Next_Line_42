/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:31:12 by leonasil          #+#    #+#             */
/*   Updated: 2025/05/23 20:12:03 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*read_file(int fd, char *rest)
{
	ssize_t	read_bytes;
	char	*buff;

	if (!rest)
		rest = ft_calloc(1, 1);
	if (!rest)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(rest);
		return (NULL);
	}
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(rest, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (is_error(read_bytes, buff, rest))
			return (NULL);
		buff[read_bytes] = '\0';
		rest = ft_strjoin_free(rest, buff);
	}
	free(buff);
	return (rest);
}

char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*update_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	free(stash);
	return (new_stash);
}

void	free_stash(char **stash)
{
	int	i;

	i = 0;
	while (i < OPEN_MAX)
	{
		if (stash[i])
		{
			free (stash[i]);
			stash[i] = NULL;
		}
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd == -1)
	{
		free_stash(stash);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}
/*
int main ()
{
    
    int fd = open("./teste.txt",O_RDWR);
     int fd1 = open("./teste2.txt",O_RDWR);
      int fd2 = open("./teste3.txt",O_RDWR);
    if (fd == -1)
        printf("Erro ao abrir o arquivo");
    else    
        printf("arquivo aberto com sucesso \n");
    
    char *line1 = get_next_line(fd);
    char *line2 = get_next_line(fd1);
    char *line3 = get_next_line(fd2);
    char *line4 = get_next_line(fd1);
	 printf("%s",line1);
     printf("%s",line2);
      printf("%s",line3);
       printf("%s",line4);
    free(line1);
    free(line2);
    free(line3);
	free(line4);
	get_next_line(-1);
}
*/
