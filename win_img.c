/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:35:43 by aait-el-          #+#    #+#             */
/*   Updated: 2019/04/27 18:14:28 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_write_img(t_mlx *p, t_vect **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j].x != -2147483648)
		{
			if (map[i][j + 1].x != -2147483648)
				ft_draw_line(map[i][j], map[i][j + 1], p);
			if (map[i + 1])
				ft_draw_line(map[i + 1][j], map[i][j], p);
			j++;
		}
		i++;
	}
}

void		ft_mlx_putpixel(t_mlx *p, int x, int y, int color)
{
	if (x >= 0 && x < p->ptr_map.img_width && y >= 0
			&& y < p->ptr_map.img_height)
	{
		p->data[y * p->ptr_map.img_width + x] = color;
	}
}

void		ft_creat_window(t_mlx *p)
{
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, p->ptr_map.img_width,
			p->ptr_map.img_height, "1337");
}

void		ft_creat_image(t_mlx *p)
{
	p->img_ptr = mlx_new_image(p->mlx_ptr, p->ptr_map.img_width,
			p->ptr_map.img_height);
	p->data = (int*)mlx_get_data_addr(p->img_ptr, p->bpp, p->size, p->endian);
}
