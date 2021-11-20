/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:39:58 by aait-el-          #+#    #+#             */
/*   Updated: 2019/04/27 18:32:59 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initial(t_mlx **p, t_vect **map)
{
	*p = (struct s_mlx*)malloc(sizeof(struct s_mlx));
	(*p)->img_ptr = NULL;
	(*p)->mlx_ptr = NULL;
	(*p)->data = NULL;
	(*p)->win_ptr = NULL;
	(*p)->bpp = malloc(4);
	(*p)->size = malloc(4);
	(*p)->endian = malloc(4);
	(*p)->type = 0;
	(*p)->ptr_map.map = map;
	(*p)->ptr_map.map_width = find_width_max(map);
	(*p)->ptr_map.map_height = find_height_max(map);
}

void	ft_initia_a(t_mlx **p, t_vect **map)
{
	ft_initial(p, map);
	ft_norm(p, map);
	if ((*p)->ptr_map.map_height > (*p)->ptr_map.map_width)
		(*p)->zoom = (double)((*p)->ptr_map.img_width
				/ (*p)->ptr_map.map_height) / 25;
	else
		(*p)->zoom = (double)((*p)->ptr_map.img_width
				/ (*p)->ptr_map.map_width) / 25;
	(*p)->point = ft_initial_vect(0, (*p)->ptr_map.max_z * (*p)->zoom * 2.5, 0)
		;
}

void	ft_norm(t_mlx **p, t_vect **map)
{
	if (((*p)->ptr_map.img_height = (int)log((double)((*p)->ptr_map.map_width *
						(*p)->ptr_map.map_height)) * 150.0) > 1310)
	{
		if ((*p)->ptr_map.img_height > 2020)
			(*p)->ptr_map.img_width = 2020;
		else
			(*p)->ptr_map.img_width = (*p)->ptr_map.img_height;
		(*p)->ptr_map.img_height = 1310;
	}
	else if (((*p)->ptr_map.img_height = (int)log((double)
					((*p)->ptr_map.map_width * (*p)->ptr_map.map_height)) *
				150.0) < 1)
	{
		if ((*p)->ptr_map.img_height < 1)
			(*p)->ptr_map.img_width = 27;
		else
			(*p)->ptr_map.img_width = (*p)->ptr_map.img_height;
		(*p)->ptr_map.img_height = 27;
	}
	else
		(*p)->ptr_map.img_width = (*p)->ptr_map.img_height;
	(*p)->ptr_map.max_z = find_depth_max(map);
}
