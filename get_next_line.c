/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:07:56 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/03/11 21:13:19 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 8

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

	if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		return (-1);
	if (!s)
		if (!(s = (char *)malloc(sizeof(char))))
			return (0);
	*line = s;
	while (ret != 0)
	{
		s = ft_strjoin(s, buf);
		if (ft_strchr(buf))
		{
			ft_trim(s);
			return(1);
		}
		ret = (read(fd, buf, BUFFER_SIZE));
	}
	return (1);
}
