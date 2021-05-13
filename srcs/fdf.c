/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:24:04 by jleu              #+#    #+#             */
/*   Updated: 2016/03/19 16:51:18 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window		new_win(void *mlx)
{
	t_window	win;

	win.largeur = WIN_WIDTH;
	win.hauteur = WIN_HEIGHT;
	win.win = mlx_new_window(mlx, win.largeur, win.hauteur, "FDF_PROJECT");
	return (win);
}

int				key_hook(int key, void *param)
{
	t_data		*data;

	data = (t_data*)param;
	if (key == 53)
	{
		ft_quit(data, 0);
	}
	else
		return (0);
	return (0);
}

int				main(int argc, char **argv)
{
	t_data		data;
	int			fd;

	data.map = NULL;
	data.win.win = NULL;
	if (argc != 2)
		ft_quit(&data, -1);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		ft_quit(&data, -2);
	ft_getpoints(fd, &data);
	if ((data.nb_pts_l < 2 && data.nb_pts_h < 2))
		ft_quit(&data, -3);
	close(fd);
	data.mlx = mlx_init();
	data.win = new_win(data.mlx);
	ft_get_min_max(&data);
	ft_resize(&data);
	ft_get_min_max(&data);
	ft_projection(&data);
	ft_get_min_max(&data);
	ft_resize(&data);
	ft_image_draw(data);
	mlx_key_hook(data.win.win, &key_hook, (void*)&data);
	mlx_loop(data.mlx);
	return (1);
}
