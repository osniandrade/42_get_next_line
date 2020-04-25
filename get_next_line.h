/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:51:46 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/04/25 10:58:06 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strchr(char *s);
char	*ft_strdup(char *s1);
int		get_next_line(int fd, char **line);
char	*ft_getln(char *s);
char	*ft_getst(char *s);
void	ft_memfix(char *tmp, char *s, char *buf);
int		ft_mainloop(char *s, int ret, int fd, char *buf);

#endif
