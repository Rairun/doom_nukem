/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:12:00 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_check(char c)
{
	if (c == '\n' || c == '\v' || c == '\t')
		return (1);
	else if (c == '\f' || c == ' ' || c == '\r')
		return (1);
	else
		return (0);
}

int				ft_atoi(char *str)
{
	int i;
	int znak;
	int res;

	i = 0;
	znak = 1;
	res = 0;
	while (ft_check(str[i]))
		i++;
	if (str[i] == '-')
		znak = -1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (ft_isdigit(str[i + 1]))
			i++;
		else
			return (0);
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * znak);
}
