/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:25:29 by jleu              #+#    #+#             */
/*   Updated: 2016/03/18 05:25:48 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_calcul(t_data *data, int l, int c)
{
	if (data->max_x != data->min_x)
		data->map[l][c].x = 5 + (int)((double)data->map[l][c].x *
							((double)data->win.largeur - 50.0) /
							(double)(data->max_x - data->min_x));
	if (data->max_y != data->min_y)
		data->map[l][c].y = 5 + (int)((double)data->map[l][c].y *
							((double)data->win.hauteur - 50.0) /
							(double)(data->max_y - data->min_y));
}

void		ft_resize(t_data *data)
{
	int		l;
	int		c;

	l = -1;
	while (data->map[++l] && (c = -1))
		while (!data->map[l][++c].end_line)
			data->map[l][c].x -= data->min_x;
	l = -1;
	while (data->map[++l] && (c = -1))
		while (!data->map[l][++c].end_line)
			data->map[l][c].y -= data->min_y;
	ft_get_min_max(data);
	l = -1;
	while (data->map[++l] && (c = -1))
		while (!data->map[l][++c].end_line)
			ft_calcul(data, l, c);
}
