/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:31:12 by leonasil          #+#    #+#             */
/*   Updated: 2025/05/28 21:04:49 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	stash[OPEN_MAX][BUFFER_SIZE + 1];
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		rb;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (!ft_strchr(stash[fd], '\n'))
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb <= 0)
			break ;
		buff[rb] = '\0';
		ft_strlcat(stash[fd], buff, BUFFER_SIZE + 1);
	}
	if (!*stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
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
       printf("%s \n",line4);
    free(line1);
    free(line2);
    free(line3);
	free(line4);
}
*/