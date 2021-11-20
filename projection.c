/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:21:36 by aait-el-          #+#    #+#             */
/*   Updated: 2019/04/18 17:36:21 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vect		**proj_caval(t_vect **map, double zoom, t_vect point)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].x != -2147483648)
		{
			map[i][j].x = zoom * ((double)j * 20 + 0.7 * cos(45) * (double)i *
					20 + point.x);
			map[i][j].y = zoom * (-(map[i][j].z == 0 ? map[i][j].z * 2.5 :
						map[i][j].z * 2.5 + point.z) + 0.7 * sin(45) *
					(double)i * 20 + point.y);
			j++;
		}
		i++;
	}
	return (map);
}

t_vect		**proj_iso(t_vect **map, double zoom, t_vect point)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].x != -2147483648)
		{
			map[i][j].x = zoom * (sqrt(2.0) / 2) * ((double)j *
					20 - (double)i * 20 + point.x);
			map[i][j].y = zoom * ((1 / sqrt(6.0)) * ((double)j * 20 +
						(double)i * 20) - sqrt(2.0 / 3.0) * (map[i][j].z == 0 ?
							map[i][j].z * 2.5 : map[i][j].z * 2.5 + point.z) +
					point.y);
			j++;
		}
		i++;
	}
	return (map);
}
