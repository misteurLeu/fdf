/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:24:43 by jleu              #+#    #+#             */
/*   Updated: 2016/03/18 04:18:34 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_putline(t_data data, t_point p1, t_point p2)
{
	double	a;
	double	b;
	int		croiss_y;
	int		croiss_x;

	croiss_y = (p1.y < p2.y);
	if (p1.x != p2.x)
	{
		a = (((double)p2.y - (double)p1.y) / ((double)p2.x - (double)p1.x));
		b = (double)p1.y - a * (double)p1.x;
		croiss_x = (p1.x < p2.x);
		while ((p1.x < p2.x && croiss_x) || (p2.x < p1.x && !croiss_x))
		{
			ft_put_pixel_to_image(data, p1.x, p1.y, 0x00ffffff);
			while (((croiss_y && p1.y < (int)(a * (double)p1.x + b))
					|| (!croiss_y && p1.y > (int)(a * (double)p1.x + b)))
					&& (p1.y += (croiss_y) ? 1 : -1))
				ft_put_pixel_to_image(data, p1.x, p1.y, 0x00ffffff);
			p1.x += (croiss_x) ? 1 : -1;
		}
	}
	if (p1.x == p2.x)
		while ((croiss_y && ++p1.y <= p2.y) || (!croiss_y && --p1.y >= p2.y))
			ft_put_pixel_to_image(data, p1.x, p1.y, 0x00ffffff);
}
