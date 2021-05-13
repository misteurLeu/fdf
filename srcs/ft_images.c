/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:25:07 by jleu              #+#    #+#             */
/*   Updated: 2016/03/18 03:48:54 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_image_draw(t_data data)
{
	int			l;
	int			c;

	data.img = mlx_new_image(data.mlx, data.win.largeur - 40,
			data.win.hauteur - 40);
	data.img_ptr =
		mlx_get_data_addr(data.img, &data.color, &data.size_line, &data.endian);
	data.color /= 8;
	l = -1;
	while (++l < data.nb_pts_h && (c = -1))
		while (++c + 1 < data.nb_pts_l)
			if (data.map[l] && !data.map[l][c + 1].end_line &&
				!data.map[l][c].end_line)
				ft_putline(data, data.map[l][c], data.map[l][c + 1]);
	c = -1;
	while (++c < data.nb_pts_l && (l = -1))
		while (++l + 1 < data.nb_pts_h)
			if (data.map[l + 1] && !data.map[l + 1][c].end_line &&
				!data.map[l][c].end_line)
				ft_putline(data, data.map[l][c], data.map[l + 1][c]);
	mlx_put_image_to_window(data.mlx, data.win.win, data.img, 20, 20);
}
