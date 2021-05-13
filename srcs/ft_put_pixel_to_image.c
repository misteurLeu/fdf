/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:25:18 by jleu              #+#    #+#             */
/*   Updated: 2016/03/18 03:07:57 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_put_pixel_to_image(t_data data, int x, int y, int color)
{
	int				cpt;
	unsigned int	c;

	c = mlx_get_color_value(data.mlx, color);
	cpt = (data.endian) ? 0 : data.color;
	while ((data.endian && cpt < data.color) || (!data.endian && cpt > 0))
	{
		if (data.size_line * y + data.color * x + cpt <
		(data.win.largeur - 40) * (data.win.hauteur - 40) * data.color &&
		data.size_line * y + data.color * x + cpt >= 0)
			data.img_ptr[data.size_line * y + data.color * x + cpt] =
			(char)(c >> (cpt * 8));
		cpt = (data.endian) ? cpt + 1 : cpt - 1;
	}
}
