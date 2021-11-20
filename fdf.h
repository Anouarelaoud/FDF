/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:21:17 by aait-el-          #+#    #+#             */
/*   Updated: 2019/04/27 18:33:42 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define KEY_MINUS 78
# define KEY_PLUS 69
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_P 34
# define KEY_I 35
# define KEY_W 13
# define KEY_Z 6
# define KEY_ESC 53
# define INT_MIN -2147483648

typedef struct	s_vect
{
	double	x;
	double	y;
	double	z;
}				t_vect;

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;
	int		x;
	int		y;
}				t_line;

typedef struct	s_map
{
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	int		max_z;
	t_vect	**map;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		*bpp;
	int		*size;
	int		*endian;
	int		type;
	double	zoom;
	t_vect	point;
	t_map	ptr_map;
}				t_mlx;

int				get_next_line(int fd, char **line);
int				ft_get_nbr_lines(char *file);
t_vect			**ft_get_map(char *file, int fd);
int				ft_get_size_line(char **str);
int				find_width_max(t_vect **map);
int				display(char *reason);
int				ft_cleanup(char **str);
int				find_height_max(t_vect **map);
int				find_depth_max(t_vect **map);
t_vect			ft_initial_vect(double x, double y, double z);
void			ft_write_img(t_mlx *p, t_vect **map);
void			ft_mlx_putpixel(t_mlx *p, int x, int y, int color);
void			ft_draw_horiz(t_line *l, t_vect v1, t_vect v2, t_mlx *p);
void			ft_draw_verti(t_line *l, t_vect v1, t_vect v2, t_mlx *p);
void			ft_draw_line(t_vect p1, t_vect p2, t_mlx *p);
int				ft_draw(t_mlx *p);
t_vect			**proj_caval(t_vect **map, double zoom, t_vect point);
t_vect			**proj_iso(t_vect **map, double zoom, t_vect point);
void			ft_switch(int key, t_mlx *p);
void			ft_move(int key, t_mlx *p);
int				ft_deal_key(int key, t_mlx *p);
int				ft_mouse_press(int button, int x, int y, t_mlx *p);
int				ft_mouse_release(int button, int x, int y, t_mlx *p);
void			ft_initial(t_mlx **p, t_vect **map);
void			ft_initia_a(t_mlx **p, t_vect **map);
void			ft_creat_window(t_mlx *p);
void			ft_creat_image(t_mlx *p);
int				ft_coloration(t_vect v1, t_vect v2, t_mlx *p);
void			ft_norm(t_mlx **p, t_vect **map);
void			menu(void);

#endif
