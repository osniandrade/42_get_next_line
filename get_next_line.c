/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:07:56 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/04/25 11:00:38 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** A function which returns a line read from a file descriptor,
** without the newline
**
** RETURN VALUES
**  1 : A line has been read
**  0 : EOF has been reached
** -1 : An error happened
*/

char	*ft_getln(char *s)
{
	int		i;
	char	*str;
	char	*rstr;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	rstr = str;
	while (i--)
		*str++ = *s++;
	*str = '\0';
	return (rstr);
}

char	*ft_getst(char *s)
{
	char	*str;

	while (*s != '\n' && *s != '\0')
		s++;
	if (*s != '\0')
		s++;
	str = ft_strdup(s);
	return (str);
}

int		ft_mainloop(char *s, int ret, int fd, char *buf)
{
	while (ft_strchr(s) != 1 && ret != 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	return (1);
}


int		get_next_line(int fd, char **line)
{
	int			ret;
	char		*buf;
	char		*tmp;
	static char	*s;

	ret = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (ft_mainloop(s, ret, fd, buf) == -1)
		return (-1);
	*line = ft_getln(s);
	tmp = s;
	if (ret == 0)
	{
		free(s);
		s = NULL;
		return (0);
	}
	s = ft_getst(s);
	free(tmp);
	return (1);
}
