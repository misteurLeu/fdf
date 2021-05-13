/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:24:57 by jleu              #+#    #+#             */
/*   Updated: 2016/03/18 04:51:46 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_get_min_max(t_data *data)
{
	int l;
	int c;

	data->max_x = data->map[0][0].x;
	data->min_x = data->map[0][0].x;
	data->max_y = data->map[0][0].y;
	data->min_y = data->map[0][0].y;
	l = 0;
	while (data->map[l])
	{
		c = 0;
		while (!data->map[l][c].end_line)
		{
			if (data->map[l][c].x > data->max_x)
				data->max_x = data->map[l][c].x;
			else if (data->map[l][c].x < data->min_x)
				data->min_x = data->map[l][c].x;
			if (data->map[l][c].y > data->max_y)
				data->max_y = data->map[l][c].y;
			else if (data->map[l][c].y < data->min_y)
				data->min_y = data->map[l][c].y;
			c++;
		}
		l++;
	}
}
