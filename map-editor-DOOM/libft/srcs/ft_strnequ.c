/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:23:36 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		t;

	i = 0;
	t = 1;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			t *= 1;
		else
			t *= 0;
		i++;
	}
	return (t);
}
