/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:26:00 by aait-el-          #+#    #+#             */
/*   Updated: 2019/04/18 17:41:06 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_nbr_lines(char *file)
{
	char	*line;
	int		fd;
	int		nbr;

	nbr = 1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		nbr++;
	return (nbr);
}

int		ft_cleanup(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int		ft_get_size_line(char **str)
{
	int		size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

t_vect	**ft_get_map(char *file, int fd)
{
	char	*line;
	t_vect	**map;
	char	**str;
	int		i;
	int		j;

	i = 0;
	map = (struct s_vect**)malloc(sizeof(struct s_vect) *
			ft_get_nbr_lines(file));
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		map[i++] = (struct s_vect*)malloc(sizeof(struct s_vect) *
				(ft_get_size_line(str) + 1));
		j = -1;
		while (++j < ft_get_size_line(str))
			map[i - 1][j].z = (double)(ft_atoi(str[j]));
		map[i - 1][j].x = -2147483648;
		if (ft_get_size_line(str) != find_width_max(map))
			display(" an error on the length of the map !");
		free(line);
		ft_cleanup(str);
	}
	map[i] = 0;
	return (map);
}
