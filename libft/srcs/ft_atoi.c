/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:17:41 by jleu              #+#    #+#             */
/*   Updated: 2016/03/18 04:27:22 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int isneg;
	int cpt;
	int temp;

	if (str == NULL)
		return (-1);
	while ((*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v'
				|| *str == '\f' || *str == ' ') && *str)
		str++;
	isneg = (*str == '-');
	str = (isneg || *str == '+') ? str + 1 : str;
	i = 0;
	cpt = 0;
	while (*str && ft_isdigit(*str))
	{
		temp = i;
		i = (isneg) ? i * 10 - (*str - 48) : i * 10 + (*str - 48);
		cpt = ((temp < 0 && i >= 0) || (temp > 0 && i <= 0)) ? cpt + 1 : cpt;
		if (cpt == 8)
			return ((isneg) ? 0 : -1);
		str++;
	}
	return (i);
}
