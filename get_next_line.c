/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:07:56 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/03/11 18:14:37 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUF_SIZE 1

/*
** A function which returns a line read from a file descriptor,
** without the newline
**
** RETURN VALUES
**  1 : A line has been read
**  0 : EOF has been reached
** -1 : An error happened
*/

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE];
	static char	*s;

	if (read(fd, buf, BUFFER_SIZE) == -1)
		return (-1);
	if (!s)
		if (!(s = (char *)malloc(sizeof(char))))
			return (NULL);
	*line = s;
	while ((ret = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (ft_strchr(buf))
			ft_strjoin()
	}
	return (1);
}
