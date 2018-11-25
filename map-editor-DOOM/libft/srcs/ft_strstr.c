/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:24:13 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *f)
{
	int i;
	int j;

	i = 0;
	if (*f == '\0')
		return ((char*)s);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == f[j] &&
				f[j] != '\0' && s[i + j] != '\0')
			j++;
		if (f[j] == '\0')
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
