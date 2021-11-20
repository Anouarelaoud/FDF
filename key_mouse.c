/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:23:16 by aait-el-          #+#    #+#             */
/*   Updated: 2019/04/19 19:02:26 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_switch(int key, t_mlx *p)
{
	if (key == KEY_P)
		p->type = 1;
	else if (key == KEY_I)
		p->type = 0;
}

void	ft_move(int key, t_mlx *p)
{
	if (key == KEY_RIGHT)
		p->point.x += 45.0;
	else if (key == KEY_LEFT)
		p->point.x -= 45.0;
	else if (key == KEY_DOWN)
		p->point.y += 45.0;
	else if (key == KEY_UP)
		p->point.y -= 45.0;
	else if (key == KEY_PLUS)
		p->zoom += 0.05;
	else if (key == KEY_MINUS)
		p->zoom -= 0.05;
	else if (key == KEY_W)
		p->point.z += 2.5;
	else if (key == KEY_Z)
		p->point.z -= 2.5;
}

int		ft_deal_key(int key, t_mlx *p)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_image(p->mlx_ptr, p->img_ptr);
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		ft_cleanup((char**)p->ptr_map.map);
		free(p);
		exit(0);
	}
	ft_switch(key, p);
	ft_move(key, p);
	ft_draw(p);
	return (key);
}

int		ft_mouse_press(int button, int x, int y, t_mlx *p)
{
	x = y;
	if (button == 4)
		p->point.z += 10;
	else if (button == 5)
		p->point.z -= 10;
	ft_draw(p);
	return (button);
}

int		ft_mouse_release(int button, int x, int y, t_mlx *p)
{
	p->point.x = (int)(x / p->zoom);
	p->point.y = (int)(y / p->zoom);
	ft_draw(p);
	return (button);
}
