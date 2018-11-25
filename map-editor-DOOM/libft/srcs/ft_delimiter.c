/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:14:43 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_delimiter(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] == '\0')
			return (count);
		while (str[i] != '\0' && str[i] != c)
			i++;
		count++;
	}
	return (count);
}
