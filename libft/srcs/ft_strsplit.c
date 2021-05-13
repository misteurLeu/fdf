/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:05:11 by jleu              #+#    #+#             */
/*   Updated: 2016/03/18 04:27:50 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*s)
	{
		i = 0;
		while (*s && *s == c)
			s++;
		while (s[i] && s[i] != c)
			i++;
		if (i != 0)
		{
			if (!(split[j] = (char*)malloc(sizeof(char) * (i + 1))))
				return (split);
			ft_strncpy(split[j++], s, i);
		}
		s += i;
	}
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	char	*str;
	size_t	nbmot;

	if (!s)
		return (NULL);
	nbmot = 0;
	str = (char*)s;
	while (*s++)
		if (*(s - 1) != c && (*(s - 2) == c || nbmot == 0))
			nbmot++;
	if (!(split = (char**)malloc(sizeof(char*) * (nbmot + 1))))
		return (NULL);
	split[nbmot] = NULL;
	s = str;
	return (ft_split(split, s, c));
}
