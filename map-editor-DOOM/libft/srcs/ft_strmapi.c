/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:23:05 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (s && f)
	{
		len = (int)ft_strlen(s);
		str = (char *)malloc(sizeof(*str) * (len + 1));
		if (str)
		{
			while (s[i] != '\0')
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
		return (NULL);
	}
	return (NULL);
}
