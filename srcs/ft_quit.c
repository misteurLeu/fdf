/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:47:24 by jleu              #+#    #+#             */
/*   Updated: 2016/03/19 17:05:10 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_quit(t_data *data, int sortie)
{
	int cpt;

	cpt = -1;
	if (data->map)
	{
		while (data->map[++cpt])
			free(data->map[cpt]);
		free(data->map);
	}
	if (data->win.win)
		mlx_destroy_window(data->mlx, data->win.win);
	if (sortie == 0)
		ft_putendl("see you again mister johns.");
	if (sortie == -1)
		ft_putendl("erreur fdf need one and only one argument");
	if (sortie == -2)
		ft_putendl("error the file can't be open");
	if (sortie == -3)
		ft_putendl("error invalid file");
	if (sortie == -4)
		ft_putendl("malloc error");
	exit(0);
}
