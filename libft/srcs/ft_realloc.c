/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:37:07 by jleu              #+#    #+#             */
/*   Updated: 2016/03/18 06:02:57 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_realloc(void **tab, int new_size)
{
	void	*new;
	int		cpt;

	if (!(new = malloc(new_size)))
		return (0);
	cpt = 0;
	while (cpt < new_size)
	{
		((char*)new)[cpt] = ((char*)*tab)[cpt];
		cpt++;
	}
	free(*tab);
	*tab = new;
	return (1);
}
