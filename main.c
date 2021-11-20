/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:20:01 by aait-el-          #+#    #+#             */
/*   Updated: 2019/04/27 18:13:46 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		display(char *reason)
{
	ft_putendl(reason);
	exit(0);
	return (0);
}

void	menu(void)
{
	ft_putendl("\n\n\t ***TAPER*** : \n");
	ft_putendl("- UP/DOWN/LEFT/RIGHT pour se deplacer\n");
	ft_putendl("- +/- pour zoom\n");
	ft_putendl("- P pour la projection cavalière\n");
	ft_putendl("- I pour la projection iso\n");
	ft_putendl("- ESC pour quitter le programme\n");
}

int		main(int argc, char **argv)
{
	int		fd;
	t_vect	**map;
	t_mlx	*p;

	if (argc != 2)
		display("usage: ./fdf file.fdf");
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		display("file not found !");
		return (0);
	}
	map = ft_get_map(argv[1], fd);
	close(fd);
	menu();
	ft_initia_a(&p, map);
	ft_creat_window(p);
	ft_creat_image(p);
	ft_draw(p);
	mlx_hook(p->win_ptr, 2, 0, ft_deal_key, p);
	mlx_hook(p->win_ptr, 4, 0, ft_mouse_press, p);
	mlx_hook(p->win_ptr, 5, 0, ft_mouse_release, p);
	mlx_loop(p->mlx_ptr);
	return (0);
}
