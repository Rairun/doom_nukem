/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:20:56 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	copy = (char *)malloc(sizeof(*copy) * (i + 1));
	if (!copy)
		return (NULL);
	while (j < i)
	{
		copy[j] = src[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
