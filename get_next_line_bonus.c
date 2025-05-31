/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 06:06:45 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/05/31 06:15:16 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];
	char		*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (buff[fd][0] != '\0')
		stash = ft_strjoin("", buff[fd]);
	else
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_file(fd, stash, buff[fd]);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	update_buff(buff[fd]);
	free(stash);
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