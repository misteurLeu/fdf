/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:24:16 by jleu              #+#    #+#             */
/*   Updated: 2016/03/19 18:39:56 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	new_point(int z, int x, int y, int end)
{
	t_point		point;

	point.x = x;
	point.y = y;
	point.x_origine = x;
	point.y_origine = y;
	point.z_origine = z * 15;
	point.end_line = end;
	return (point);
}

static int		ssl(char **str)
{
	int			cpt;

	cpt = 0;
	while (str[cpt])
		cpt++;
	return (cpt);
}

static int		ft_n(int *cpt_l, int *cpt_c, t_point **p, char *l)
{
	char		**line_splited;

	*cpt_c = 0;
	line_splited = ft_strsplit(l, ' ');
	if (!(p[*cpt_l] =
		(t_point*)malloc(sizeof(t_point) * (ssl(line_splited) + 1))))
		return (0);
	while (line_splited[*cpt_c])
	{
		p[*cpt_l][*cpt_c] =
			new_point(ft_atoi(line_splited[*cpt_c]), *cpt_c, *cpt_l, 0);
		(*cpt_c)++;
	}
	p[*cpt_l][*cpt_c] = new_point(0, 0, 0, 1);
	free(l);
	while (*line_splited)
	{
		free(*line_splited);
		line_splited++;
	}
	return (1);
}

static void		line_valid(char *line, t_data *data)
{
	int			cpt;

	cpt = 0;
	if (!line[0])
	{
		free(line);
		ft_quit(data, -3);
	}
	while (line[cpt])
	{
		if (!ft_isdigit(line[cpt]) && line[cpt] != ' ' && line[cpt] != '-')
		{
			free(line);
			ft_quit(data, -3);
		}
		cpt++;
	}
}

void			ft_getpoints(int fd, t_data *data)
{
	char		*line;
	int			cpt_line;
	int			cpt_column;
	int			retour;

	cpt_line = 0;
	if (!(data->map = (t_point**)malloc(sizeof(t_point*))))
		ft_quit(data, -4);
	data->map[0] = NULL;
	while ((retour = get_next_line(fd, &line)) > 0)
	{
		data->map[cpt_line] = NULL;
		line_valid(line, data);
		if (!(ft_n(&cpt_line, &cpt_column, data->map, line)))
			ft_quit(data, -4);
		cpt_line++;
		if (!(ft_realloc((void**)&(data->map),
			sizeof(t_point*) * (cpt_line + 1))))
			ft_quit(data, -4);
	}
	if (retour < 0)
		ft_quit(data, -3);
	data->map[cpt_line] = NULL;
	data->nb_pts_h = cpt_line;
	data->nb_pts_l = cpt_column;
}
