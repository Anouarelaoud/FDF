/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:32:01 by aait-el-          #+#    #+#             */
/*   Updated: 2019/04/19 19:02:19 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_coloration(t_vect p1, t_vect p2, t_mlx *p)
{
	if (p1.z == 0 && p2.z == 0)
		return (0x8DA100);
	else if (p1.z == p->ptr_map.max_z && p2.z == p->ptr_map.max_z)
		return (0xFFFFFF);
	else if ((p1.z < 0 && p2.z == 0) || (p2.z < 0 && p1.z == 0))
		return (0x1966FF);
	else if (p1.z < 0 && p2.z < 0)
		return (0x1966FF + (p1.z > p2.z ? p2.z + 2 : p1.z + 2));
	else if ((p1.z > 0 && p2.z == 0) || (p2.z > 0 && p1.z == 0))
		return (0xB37700 + (p1.z > p2.z ? p2.z + 10 : p1.z + 10));
	else if ((p1.z > 0 && p2.z != 0) || (p2.z > 0 && p1.z != 0))
		return (0xFFAA00 + (p1.z > p2.z ? p1.z + 10 : p2.z + 10));
	return (0xFFFFFF);
}

void		ft_draw_horiz(t_line *l, t_vect v1, t_vect v2, t_mlx *p)
{
	l->cumul = l->dx / 2;
	l->i = 0;
	while (++l->i <= l->dx)
	{
		l->x += l->xinc;
		l->cumul += l->dy;
		if (l->cumul >= l->dx)
		{
			l->cumul -= l->dx;
			l->y += l->yinc;
		}
		ft_mlx_putpixel(p, l->x, l->y, ft_coloration(v1, v2, p));
	}
}

void		ft_draw_verti(t_line *l, t_vect v1, t_vect v2, t_mlx *p)
{
	l->cumul = l->dy / 2;
	l->i = 0;
	while (++l->i <= l->dy)
	{
		l->y += l->yinc;
		l->cumul += l->dx;
		if (l->cumul >= l->dy)
		{
			l->cumul -= l->dy;
			l->x += l->xinc;
		}
		ft_mlx_putpixel(p, l->x, l->y, ft_coloration(v1, v2, p));
	}
}

void		ft_draw_line(t_vect v1, t_vect v2, t_mlx *p)
{
	t_line	*l;

	l = (struct s_line *)malloc(sizeof(struct s_line));
	l->x = v1.x;
	l->y = v1.y;
	l->dx = v2.x - v1.x;
	l->dy = v2.y - v1.y;
	l->xinc = (l->dx > 0) ? 1 : -1;
	l->yinc = (l->dy > 0) ? 1 : -1;
	l->dx = abs(l->dx);
	l->dy = abs(l->dy);
	ft_mlx_putpixel(p, l->x, l->y, ft_coloration(v1, v2, p));
	if (l->dx > l->dy)
		ft_draw_horiz(l, v1, v2, p);
	else
		ft_draw_verti(l, v1, v2, p);
	free(l);
}

int			ft_draw(t_mlx *p)
{
	ft_bzero(p->data, p->ptr_map.img_width * p->ptr_map.img_height * 4);
	p->type == 1 ?
		ft_write_img(p, (t_vect**)proj_iso(p->ptr_map.map, p->zoom, p->point))
		: ft_write_img(p, (t_vect**)proj_caval(p->ptr_map.map, p->zoom,
					p->point));
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	return (0);
}
