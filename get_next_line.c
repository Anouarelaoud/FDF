/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:38:25 by aait-el-          #+#    #+#             */
/*   Updated: 2019/04/18 17:31:31 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_next_line(int fd, char **line)
{
	static char		*str1[4864];
	char			str2[5];
	int				nbr_oct;
	int				i;

	i = 0;
	if (fd == -1 || !line || read(fd, str2, 0) < 0)
		return (-1);
	if (str1[fd] == NULL)
		str1[fd] = ft_strnew(1);
	while ((nbr_oct = read(fd, str2, 4)) > 0)
	{
		str2[nbr_oct] = '\0';
		str1[fd] = ft_strjoin(str1[fd], str2);
		if (ft_strchr(str2, '\n'))
			break ;
	}
	if (ft_strlen(str1[fd]) == 0)
		return (0);
	while (str1[fd][i] != '\0' && str1[fd][i] != '\n')
		i++;
	*line = ft_strsub(str1[fd], 0, i);
	str1[fd] = ft_strdup(str1[fd] + i + 1);
	return (1);
}
