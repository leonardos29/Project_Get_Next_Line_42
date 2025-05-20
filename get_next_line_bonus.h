/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:30:31 by leonasil          #+#    #+#             */
/*   Updated: 2025/05/20 18:59:33 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *rest);
char	*get_line(char *buffer);
char	*update_stash(char *stash);
char	*ft_strjoin_free(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		is_error(ssize_t result, char *buff, char *rest);

#endif