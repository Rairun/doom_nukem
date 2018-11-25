/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:24:23 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim(char *s)
{
	int i;
	int len;
	int sp;

	len = (int)ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	sp = i;
	if (s[i] != '\0')
	{
		i = len - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			sp++;
		}
	}
	return (len - sp);
}

char		*ft_strtrim(char const *s)
{
	char	*copy;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	length = ft_trim((char *)s);
	copy = (char *)malloc(sizeof(*copy) * (length + 1));
	if (!copy)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < length)
	{
		copy[j] = s[i];
		j++;
		i++;
	}
	copy[j] = '\0';
	return (copy);
}
