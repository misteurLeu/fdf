/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:26:54 by jleu              #+#    #+#             */
/*   Updated: 2016/03/19 16:55:28 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define WIN_WIDTH 2048
# define WIN_HEIGHT 1024

typedef struct	s_point
{
	int			x;
	int			y;
	int			x_origine;
	int			y_origine;
	int			z_origine;
	int			end_line;
}				t_point;

typedef struct	s_window
{
	void		*win;
	int			largeur;
	int			hauteur;
}				t_window;

typedef struct	s_data
{
	t_window	win;
	void		*mlx;
	t_point		**map;
	int			nb_pts_h;
	int			nb_pts_l;
	int			max_x;
	int			max_y;
	int			min_x;
	int			min_y;
	void		*img;
	char		*img_ptr;
	int			color;
	int			size_line;
	int			endian;
}				t_data;

void			ft_getpoints(int fd, t_data *data);
void			ft_put_pixel_to_image(t_data data, int x, int y, int color);
void			ft_putline(t_data data, t_point a, t_point b);
void			ft_image_draw(t_data data);
void			ft_resize(t_data *data);
void			ft_get_min_max(t_data *data);
void			ft_projection(t_data *data);
void			ft_quit(t_data *data, int sortie);

#endif
