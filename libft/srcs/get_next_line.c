/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:09:19 by jleu              #+#    #+#             */
/*   Updated: 2016/02/11 21:46:50 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cpyclearbuf(char (*buf)[BUFF_SIZE + 1], size_t dec)
{
	char		*temp;

	temp = ft_strdup(*buf);
	ft_bzero(*buf, BUFF_SIZE + 1);
	ft_strcpy(*buf, temp + dec);
	free(temp);
	return (1);
}

static int		getendline(char *b, size_t pb)
{
	while (b[pb] != '\n' && b[pb] && b[pb] != 26)
		pb++;
	return (pb);
}

int				get_next_line(int const fd, char **line)
{
	static char	b[BUFF_SIZE + 1];
	size_t		pb;
	char		*tmp;
	int			ret;

	if ((line == NULL || fd < 0) || (tmp = NULL))
		return (-1);
	*line = NULL;
	while ((*b != '\n' && !(pb = 0)) || !(*line))
	{
		if ((!*b || *b == 26)
			&& ((ret = read(fd, b, BUFF_SIZE)) < 1))
		{
			ft_bzero(b, BUFF_SIZE + 1);
			return ((*line) ? 1 : ret);
		}
		pb = getendline(b, pb);
		tmp = *line;
		*line = ft_strnew(pb + ft_strlen(tmp) + 1);
		ft_strcpy(*line, tmp);
		ft_strncat(*line, b, pb);
		(tmp) ? free(tmp) : tmp;
		cpyclearbuf(&b, pb);
	}
	return (cpyclearbuf(&b, 1));
}
