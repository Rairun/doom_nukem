/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:24:03 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = -1;
	len = ((int)ft_strlen(str)) - 1;
	while (++i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		len--;
	}
	return (str);
}
