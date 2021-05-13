/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:24:30 by jleu              #+#    #+#             */
/*   Updated: 2016/03/18 00:24:32 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_projection(t_data *data)
{
	int		l;
	int		c;
	double	x;
	double	y;
	double	z;

	l = -1;
	while (data->map[++l] && (c = -1))
		while (!data->map[l][++c].end_line)
		{
			x = (double)data->map[l][c].x;
			y = (double)data->map[l][c].y;
			z = (double)data->map[l][c].z_origine;
			data->map[l][c].x = (0.71 * (x - y));
			data->map[l][c].y = (-0.82 * z + 0.41 * (x + y));
		}
}
