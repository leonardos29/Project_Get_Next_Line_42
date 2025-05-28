/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:04:59 by leonasil          #+#    #+#             */
/*   Updated: 2025/05/28 21:05:06 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		rb;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb <= 0)
			break ;
		buff[rb] = '\0';
		ft_strlcat(stash, buff, BUFFER_SIZE + 1);
	}
	if (!*stash)
		return (NULL);
	line = extract_line(stash);
	return (line);
}
/*
int main ()
{
    
    int fd = open("./teste.txt",O_RDWR);
    if (fd == -1)
        printf("Erro ao abrir o arquivo");
    else    
        printf("arquivo aberto com sucesso \n");
    
    char *line1 = get_next_line(fd);
	char *line2 = get_next_line(fd);
    printf("%s",line1);
	printf("%s",line2);
	free(line1);
	free(line2);
	close(fd);
}
*/
