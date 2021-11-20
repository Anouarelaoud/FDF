/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:27:52 by aait-el-          #+#    #+#             */
/*   Updated: 2019/04/18 17:42:20 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			find_width_max(t_vect **map)
{
	int		width;

	width = 0;
	while (map[0][width].x != -2147483648)
		width++;
	return (width);
}

int			find_height_max(t_vect **map)
{
	int		height;

	height = 0;
	while (map[height])
	{
		height++;
	}
	return (height);
}

int			find_depth_max(t_vect **map)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = INT_MIN;
	while (map[i])
	{
		j = 0;
		while (map[i][j].x != -2147483648)
		{
			if (map[i][j].z > max)
				max = map[i][j].z;
			j++;
		}
		i++;
	}
	return (max);
}

t_vect		ft_initial_vect(double x, double y, double z)
{
	t_vect	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}
