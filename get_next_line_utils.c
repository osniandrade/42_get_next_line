/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:46:24 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/03/12 19:15:28 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	if (!s || *s == '\0')
		return (0);
	while (*s++)
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*ret;
	int		total;
	int		i[2];

	if (!s1 && !s2)
		return (NULL);
	i[0] = ft_strlen((char *)s1);
	i[1] = ft_strlen((char *)s2);
	total = (i[0] + i[1] + 1);
	if (!(result = (char *)malloc(sizeof(char) * total)))
		return (NULL);
	ret = result;
	while (i[0]--)
		*result++ = *s1++;
	while (i[1]--)
		*result++ = *s2++;
	*result = '\0';
	return (ret);
}

int			ft_strchr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

char		*ft_strdup(char *s1)
{
	char	*s2;
	char	*str;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	str = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (str);
}
