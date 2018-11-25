/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/14 17:06:35 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*transform(char *copy, int n, int len, int isnegative)
{
	copy[len] = '\0';
	len -= 1;
	while (len >= isnegative)
	{
		copy[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (copy);
}

char		*ft_itoa(int n)
{
	char	*copy;
	int		a;
	int		b;

	copy = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	a = 0;
	b = ft_count_char(n);
	if (!(copy = (char *)malloc(sizeof(*copy) * (b + 1))))
		return (NULL);
	if (n < 0)
	{
		copy[0] = '-';
		n = -n;
		a = 1;
	}
	return (transform(copy, n, b, a));
}
