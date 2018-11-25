/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:14:38 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_char(int n)
{
	int	count;
	int	znak;

	count = 0;
	znak = 0;
	if (n < 0)
		znak = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count + znak);
}
