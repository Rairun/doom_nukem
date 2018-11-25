/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:24:18 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;

	i = 0;
	if (s)
	{
		copy = (char *)malloc(sizeof(*copy) * (len + 1));
		if (copy)
		{
			while (i < len && s[start] != '\0')
				copy[i++] = s[start++];
			copy[i] = '\0';
			return (copy);
		}
		return (NULL);
	}
	return (NULL);
}
